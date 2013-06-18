//
//  Label.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 18.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "Label.h"

#include <GLUT/GLUT.h>

Label::Label(const std::string& string)
{
    setString(string);
    setColor(Color3f(0, 0, 1));
}

void Label::setString(const std::string& string)
{
    _string = string;
    float width = glutBitmapLength(GLUT_BITMAP_HELVETICA_18,
                                   reinterpret_cast<const unsigned char *>(_string.c_str()));
    setSize(CGSizeMake(width, 1));
}

void Label::draw()
{
    glRasterPos2d(0, 0);
    for (const char* chr = _string.c_str(); *chr != '\0'; chr++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *chr);
    }
}
