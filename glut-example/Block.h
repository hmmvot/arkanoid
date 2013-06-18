//
//  Block.h
//  glut-example
//
//  Created by Alexander Sokolenko on 18.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Block__
#define __glut_example__Block__

#include "GameObject.h"

class Block : public GameObject
{
protected:
    SYNTHESIZE_READONLY(bool, _isTouched, isTouched);
    
public:
    Block();
    
    virtual void touch();
    
    virtual void draw();
    virtual void reset();
    virtual void update(float dt);
};

#endif /* defined(__glut_example__Block__) */
