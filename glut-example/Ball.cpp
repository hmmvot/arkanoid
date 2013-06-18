//
//  Ball.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "Ball.h"
#include "GameCommon.h"

#include <GLUT/GLUT.h>
#include <math.h>


Ball::Ball() : GameObject()
{
    Object::setSize(CGSizeMake(1, 1));
    setColor(Color3f(1.0f, 0.0f, 0.0f));
}

float Ball::radius() const
{
    return size().width / 2;
}

float Ball::radiusInPoints() const
{
    return radius() * cellSize().width;
}

void Ball::draw()
{
    
    glTranslatef(sizeInPoints().width/2, sizeInPoints().height/2, 0);
    float x, y;
    float radius = this->radiusInPoints();
    glBegin(GL_LINES);
    x = (float)radius * cos(359 * M_PI/180.0f);
    y = (float)radius * sin(359 * M_PI/180.0f);
    for(int j = 0; j < 360; j++)
    {
        glVertex2f(x, y);
        x = (float)radius * cos(j * M_PI/180.0f);
        y = (float)radius * sin(j * M_PI/180.0f);
        glVertex2f(x, y);
    }
    glEnd();
}
