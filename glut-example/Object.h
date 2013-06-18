//
//  Object.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Object__
#define __glut_example__Object__

#include "Macroses.h"
#include "Geometry.h"

struct Color4f
{
    float r, g, b, a;
    Color4f(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
};

struct Color3f
{
    float r, g, b;
    Color3f(float r, float g, float b) : r(r), g(g), b(b) {}
};

class Object
{
    SYNTHESIZE(CGPoint,   _position,      position,       setPosition);
    SYNTHESIZE(CGPoint,   _anchorPoint,   anchorPoint,    setAnchorPoint);
    SYNTHESIZE(CGSize,    _size,          size,           setSize);

protected:
    Color4f _color;

public:
    Object();
    virtual ~Object() {}
    
    virtual void setColor(const Color4f& _color);
    virtual void setColor(const Color3f& _color);
    virtual Color4f getColor() const;
    virtual void setOpacity(float opacity);
    virtual float getOpacity() const;
    
    virtual CGPoint positionUnrelativeAnchor() const;
    
    virtual void visit();
    virtual void draw() {}
    virtual void update(float dt) {}
    virtual void keyboard(int key, bool isDown) {}
};

#endif /* defined(__glut_example__Object__) */
