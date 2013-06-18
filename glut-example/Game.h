//
//  Game.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Game__
#define __glut_example__Game__

#include "Scene.h"
#include "Geometry.h"

#include <list>

const int kBlocksInLine = 12;
const int kBlocksInColumn = 5;
const unsigned kMaxLevel = 5;
const CGPoint kBallMinVelocity = { -10.0f, -10.0f };
const float kPlatformMinAbsVelocity = 15.0f;

class Platform;
class Ball;
class Block;
class Label;
typedef std::list<Block*> BlocksList;
class Game : public Scene
{
protected:
    Platform *_platform;
    Ball *_ball;
    BlocksList _blocks;
    
    Label *_levelLabel;
    unsigned _levelNumber;
    
    float _platformAbsVelocity;
    
    bool _isPaused;
    bool _needReset;
    
public:
    Game();
    ~Game();
    
    virtual void visit();
    virtual void draw();
    virtual void update(float dt);
    virtual void keyboard(int key, bool isDown);
    
    virtual void reset();
    
    virtual void gameOver();
    virtual void nextLevel();
};

#endif /* defined(__glut_example__Game__) */
