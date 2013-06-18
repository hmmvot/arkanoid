//
//  Block.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 18.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "Block.h"

#include <GLUT/GLUT.h>


Block::Block() : GameObject()
{
    _size = CGSizeMake(2, 1);
    _isTouched = false;
    setColor(Color3f(0.0f, 0.0f, 1.0f));
}

void Block::draw()
{
    CGSize s = sizeInPoints();
    glLineWidth(2.0f);
    float border = 2.0f;
    glBegin(GL_LINES);
        glVertex2d(border, border);
        glVertex2d(s.width - border, border);
        
        glVertex2d(s.width - border, border);
        glVertex2d(s.width - border, s.height - border);
        
        glVertex2d(s.width - border, s.height - border);
        glVertex2d(border, s.height - border);
        
        glVertex2d(border, s.height - border);
        glVertex2d(border, border);
    glEnd();
}

void Block::touch()
{
    _isTouched = true;
}

void Block::reset()
{
    _isTouched = false;
    _color.a = 1.0f;
}

void Block::update(float dt)
{
    if (_isTouched && _color.a > 0)
    {
        _color.a -= 2.0f*dt;
        _color.a = _color.a < 0 ? 0 : _color.a;
    }
}
