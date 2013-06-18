//
//  Director.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "Director.h"
#include <time.h>

#include <GLUT/GLUT.h>
#include <assert.h>

#include "Scene.h"


Director Director::DirectorInstance;

Director& Director::getInstance()
{
    return DirectorInstance;
}

Director::Director()
{
    currentScene = 0;
}

void Director::reshape(GLsizei width, GLsizei height)
{
    getInstance()._screenSize = CGSizeMake(width, height);
    
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0.0, (GLdouble)width,
               0.0, (GLdouble)height);
}

void Director::display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    Director::getInstance().visitScene();
    
    glutSwapBuffers();
}

void Director::timer(int timerId)
{
    static const float timePerFrameInMilliseconds = 1000.0f/60.0f;
    
    glutPostRedisplay();
    glutTimerFunc(timePerFrameInMilliseconds, timer, 0);
    
    getInstance().update(timePerFrameInMilliseconds/1000.0f);
}

void Director::keyDown(int key, int x, int y)
{
    getInstance().keyboard(key, true);
}

void Director::keyUp(int key, int x, int y)
{
    getInstance().keyboard(key, false);
}

void Director::keyDown(unsigned char key, int x, int y)
{
    getInstance().keyboard(key, true);
}

void Director::keyUp(unsigned char key, int x, int y)
{
    getInstance().keyboard(key, false);
}

void Director::run(Scene *scene)
{
    assert(currentScene == 0);
    assert(scene);
    
    currentScene = scene;
}

void Director::visitScene()
{
    if (currentScene == 0)
    {
        return;
    }
    
    currentScene->visit();
}

void Director::update(float dt)
{
    if (currentScene == 0)
    {
        return;
    }
    
    currentScene->update(dt);
}

void Director::keyboard(int key, bool isDown)
{
    if (currentScene == 0)
    {
        return;
    }
    
    currentScene->keyboard(key, isDown);
}
