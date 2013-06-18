//
//  Geometry.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Geometry__
#define __glut_example__Geometry__

#include <CoreGraphics/CGGeometry.h>

typedef CGPoint CGPoint;
CGPoint operator+(const CGPoint& p0, const CGPoint& p1);
CGPoint operator-(const CGPoint& p0, const CGPoint& p1);
CGPoint operator*(const CGPoint& p0, float v);
float length(const CGPoint& p0);

CGPoint point(float x, float y);

#endif /* defined(__glut_example__Geometry__) */
