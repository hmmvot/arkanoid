//
//  Object.c
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "Object.h"
#include <GLUT/GLUT.h>


Object::Object() : _color(0, 0, 0, 1.0f)
{
    _anchorPoint = point(0.5f, 0.5f);
}

void Object::visit()
{
    glPushMatrix();
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    CGPoint p = positionUnrelativeAnchor();
    glTranslatef(p.x, p.y, 0);
    glColor4f(_color.r, _color.g, _color.b, _color.a);
    draw();
    glPopMatrix();
}

CGPoint Object::positionUnrelativeAnchor() const
{
    return point(position().x - anchorPoint().x*size().width,
                 position().y - anchorPoint().y*size().height);
}

void Object::setColor(const Color4f& c)
{
    _color = c;
}

void Object::setColor(const Color3f& c)
{
    _color.r = c.r;
    _color.g = c.g;
    _color.b = c.b;
}

Color4f Object::getColor() const
{
    return _color;
}

void Object::setOpacity(float opacity)
{
    _color.a = opacity;
}

float Object::getOpacity() const
{
    return _color.a;
}
