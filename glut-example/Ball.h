//
//  Ball.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Ball__
#define __glut_example__Ball__

#include "GameObject.h"

class Ball : public GameObject
{
public:
    Ball();
    
    virtual float radius() const;
    virtual float radiusInPoints() const;
    virtual void draw();
};

#endif /* defined(__glut_example__Ball__) */
