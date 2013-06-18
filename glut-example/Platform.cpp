//
//  Platform.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "Platform.h"
#include "GameCommon.h"

#include <GLUT/GLUT.h>

Platform::Platform() : GameObject()
{
    Object::setSize(CGSizeMake(8, 1));
    setColor(Color3f(1, 1, 1));
}

void Platform::draw()
{
    CGSize s = sizeInPoints();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2d(0, 0);
        glVertex2d(s.width, 0);
    
        glVertex2d(s.width, 0);
        glVertex2d(s.width, s.height);
    
        glVertex2d(s.width, s.height);
        glVertex2d(0, s.height);
    
        glVertex2d(0, s.height);
        glVertex2d(0, 0);
    glEnd();
}
