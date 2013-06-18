//
//  Geometry.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "Geometry.h"
#include <math.h>


float length(const CGPoint& p)
{
    return (sqrt(p.x*p.x + p.y*p.y));
}

CGPoint operator+(const CGPoint& p0, const CGPoint& p1)
{
    return point(p0.x + p1.x, p0.y + p1.y);
}

CGPoint operator-(const CGPoint& p0, const CGPoint& p1)
{
    return point(p0.x - p1.x, p0.y - p1.y);
}

CGPoint operator*(const CGPoint& p0, float v)
{
    return point(p0.x*v, p0.y*v);
}

CGPoint point(float x, float y)
{
    return CGPointMake(x, y);
}
