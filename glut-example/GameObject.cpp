//
//  GameObject.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "GameObject.h"
#include "GameCommon.h"

#include <GLUT/GLUT.h>

#include <assert.h>

GameObject::GameObject() : _velocity(point(0, 0))
{

}

void GameObject::setSize(const CGSize &)
{
    // you can not set size manually
    assert(0);
}

CGSize GameObject::sizeInPoints() const
{
    return toPoints(size());
}

CGPoint GameObject::positionInPoints() const
{
    return toPoints(position());
}

CGPoint GameObject::positionUnrelativeAnchorInPoints() const
{
    return toPoints(positionUnrelativeAnchor());
}

void GameObject::visit()
{
    glPushMatrix();
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    CGPoint p = positionUnrelativeAnchorInPoints();
    glTranslatef(p.x, p.y, 0);
    glColor4f(_color.r, _color.g, _color.b, _color.a);
    draw();
    glPopMatrix();
}

CGPoint GameObject::velocityInPoints() const
{
    return toPoints(_velocity);
}
