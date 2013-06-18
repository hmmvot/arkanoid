//
//  Game.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "Game.h"
#include "Director.h"
#include "GameCommon.h"

#include <GLUT/GLUT.h>

#include "Platform.h"
#include "Ball.h"
#include "Block.h"

#include "Label.h"

#include <math.h>
#include <algorithm>
#include <sstream>


inline float clamp(float val, float min, float max)
{
    return val < min ? min : val > max ? max : val;
}

Game::Game()
{
    updateCellSize();
    
    _isPaused = true;
    _needReset = true;
    _levelNumber = 0;
    
    _platform = new Platform();    
    _ball = new Ball();

    for (int i = 0; i < kBlocksInColumn*kBlocksInLine; i++)
    {
        Block *block = new Block();
        block->setAnchorPoint(point(0, 0));
        _blocks.push_back(block);
    }
    
    _levelLabel = new Label("");
    _levelLabel->setColor(Color3f(0, 1, 0));
    _levelLabel->setPosition(point(size().width/2, size().height - 32.0f));
    
    reset();
    
    _levelLabel->setString("Level 1 (press spacebar to start)");
}

Game::~Game()
{
    delete _platform;
    delete _ball;
    
    for (BlocksList::iterator i = _blocks.begin();
         i != _blocks.end();
         ++i)
    {
        delete *i;
        *i = 0;
    }
    
    delete _levelLabel;
}

void Game::reset()
{
    _needReset = false;
    
    std::stringstream ss;
    ss << "Level " << (_levelNumber + 1);
    _levelLabel->setString(ss.str());
    
    _platform->setPosition(point(gridSize.width/2, 0.5f));
    _platformAbsVelocity = kPlatformMinAbsVelocity + (float)_levelNumber/2;
    
    _ball->setPosition(point(25, 10));
    _ball->setVelocity(kBallMinVelocity - point(_levelNumber, _levelNumber));
    
    float blocksShiftLeft = (gridSize.width - kBlocksInLine*2)/2;
    float blocksShiftTop = 5.0f;
    int n = 0;
    for (BlocksList::iterator i = _blocks.begin();
         i != _blocks.end();
         ++i, ++n)
    {
        int k = n / kBlocksInLine;
        int j = n % kBlocksInLine;
        Block *block = *i;
        block->reset();
        block->setPosition(point(j*block->size().width + blocksShiftLeft,
                                 gridSize.height - k - blocksShiftTop));
    }
}

void Game::nextLevel()
{
    std::stringstream ss;
    if (_levelNumber < kMaxLevel - 1)
    {
        ss << "Level " << (_levelNumber + 1) << " complete! (press spacebar to continue)";
    }
    else
    {
        ss << "Ultimate win! (press space to restart)";
    }
    _levelLabel->setString(ss.str());
    
    _levelNumber++;
    _levelNumber = _levelNumber < kMaxLevel ? _levelNumber : 0;
    _needReset = true;
    _isPaused = true;
}

void Game::gameOver()
{
    std::stringstream ss;
    ss << "Game Over on level " << (_levelNumber + 1) << " (press spacebar to restart)";
    _levelLabel->setString(ss.str());
    _levelNumber = 0;
    _needReset = true;
    _isPaused = true;
}

void Game::visit()
{
    glPushMatrix();
    
    glTranslatef(position().x, position().y, 0);
    
    draw();
    
    // draw object on scene
    _platform->visit();
    _ball->visit();
    
    for (BlocksList::iterator i = _blocks.begin();
         i != _blocks.end();
         ++i)
    {
        (*i)->visit();
    }
    
    _levelLabel->visit();
    
    glPopMatrix();
}

void Game::draw()
{
    // draw borders
    glLineWidth(1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(0, 0);
        glVertex2d(size().width, 0);
    
        glVertex2d(size().width, 0);
        glVertex2d(size().width, size().height);
    
        glVertex2d(size().width, size().height);
        glVertex2d(0, size().height);
    
        glVertex2d(0, size().height);
        glVertex2d(0, 0);
    glEnd();
}

enum CollisionType
{
    CollisionTypeNone,
    CollisionTypeVertical,
    CollisionTypeHorizontal
};
CollisionType collide(GameObject *dynamicObj, GameObject *staticObj)
{
    CGRect r0 = CGRectMake(dynamicObj->positionUnrelativeAnchor().x,
                           dynamicObj->positionUnrelativeAnchor().y,
                           dynamicObj->size().width,
                           dynamicObj->size().height);
    
    CGRect r1 = CGRectMake(staticObj->positionUnrelativeAnchor().x,
                           staticObj->positionUnrelativeAnchor().y,
                           staticObj->size().width,
                           staticObj->size().height);
    
    CGRect intersect = CGRectIntersection(r0, r1);
    if (!CGRectIsNull(intersect))
    {
        float dx = intersect.size.width;
        float dy = intersect.size.height;
        
        if (dx < dy)
        {
            int s = intersect.origin.y + dy/2 >= staticObj->position().y ? 1 : -1;
            dynamicObj->setPosition(dynamicObj->position() + toGrid(point(0, s*dy*2)));
            return CollisionTypeHorizontal;
        }
        else
        {
            int s = intersect.origin.x + dx/2 >= staticObj->position().x ? 1 : -1;
            dynamicObj->setPosition(dynamicObj->position() + toGrid(point(s*dx*2, 0)));
            return CollisionTypeVertical;
        }
    }
    
    return CollisionTypeNone;
}

void Game::update(float dt)
{
    // update cell's size, scene's size and scene's position
    updateCellSize();
    _size = CGSizeMake(cellSize().width*gridSize.width,
                 cellSize().height*gridSize.height);
    
    CGSize screenSize = Director::getInstance().screenSize();
    _position = point((screenSize.width - _size.width) / 2,
                      (screenSize.height - _size.height) / 2);
    
    _levelLabel->setPosition(point(size().width/2, size().height - 32.0f));
    
    
    if (_isPaused)
    {
        return;
    }
    
    if (_needReset)
    {
        reset();
        return;
    }
    
    
    // move platform
    _platform->setPosition(_platform->position() + _platform->velocity() * dt);
    
    // fix platform's position in game field bounds
    float newX = clamp(_platform->position().x,
                       _platform->size().width/2,
                       gridSize.width - _platform->size().width/2);
    _platform->setPosition(point(newX, _platform->position().y));
    
    
    // move ball
    _ball->setPosition(_ball->position() + _ball->velocity() * dt);
    
    // process collisions between ball and borders
    CGPoint ballPosition = _ball->position();
    if (ballPosition.x - _ball->size().width/2 < 0
        || ballPosition.x + _ball->size().width/2 > gridSize.width)
    {
        _ball->setVelocity(point(-_ball->velocity().x, _ball->velocity().y));
    }
    if (ballPosition.y - _ball->size().height/2 < 0
        || ballPosition.y + _ball->size().height/2 > gridSize.height)
    {
        _ball->setVelocity(point(_ball->velocity().x, -_ball->velocity().y));
    }
    
    if (_ball->position().y - _ball->size().height/2 < 0)
    {
        gameOver();
        return;
    }
    
    // process collisions between ball and platform
    CollisionType ct = collide(_ball, _platform);
    switch (ct)
    {
        case CollisionTypeHorizontal:
            _ball->setVelocity(point(-_ball->velocity().x, _ball->velocity().y));
            break;
            
        case CollisionTypeVertical:
            _ball->setVelocity(point(_ball->velocity().x, -_ball->velocity().y));
            break;
        
        default:
            break;
    }
    
    // process collisions between ball and blocks
    unsigned touchedBlocks = 0;
    bool b = false;
    for (BlocksList::iterator i = _blocks.begin();
         i != _blocks.end();
         ++i)
    {
        (*i)->update(dt);
        
        if ((*i)->isTouched())
        {
            touchedBlocks++;
            continue;
        }
        
        if (b)
        {
            continue;
        }
        
        CollisionType ct = collide(_ball, *i);
        switch (ct)
        {
            case CollisionTypeHorizontal:
                _ball->setVelocity(point(-_ball->velocity().x, _ball->velocity().y));
                break;
                
            case CollisionTypeVertical:
                _ball->setVelocity(point(_ball->velocity().x, -_ball->velocity().y));
                break;
                
            default:
                break;
        }
        
        if (ct != CollisionTypeNone)
        {
            b = true;
            touchedBlocks++;
            (*i)->touch();
        }
    }
    
    if (touchedBlocks >= _blocks.size())
    {
        nextLevel();
        return;
    }
    
    
    // fix ball's position in game field bounds
    newX =          clamp(_ball->position().x,
                          _ball->size().width/2,
                          gridSize.width - _ball->size().height/2);
    float newY =    clamp(_ball->position().y,
                          _ball->size().height/2,
                          gridSize.height - _ball->size().height/2);
    _ball->setPosition(point(newX, newY));
}

void Game::keyboard(int key, bool isDown)
{
    switch (key)
    {
        case GLUT_KEY_LEFT: {
            if (isDown)
            {
                _platform->setVelocity(point(-_platformAbsVelocity, 0));
            }
            else
            {
                _platform->setVelocity(point(0, 0));
            }
        } break;
            
            
        case GLUT_KEY_RIGHT: {
            if (isDown)
            {
                _platform->setVelocity(point(_platformAbsVelocity, 0));
            }
            else
            {
                _platform->setVelocity(point(0, 0));
            }
        } break;
            
        case 32: { // SPACEBAR
            _isPaused = false;
        } break;
            
        default:
            break;
    }
}