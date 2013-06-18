//
//  Scene.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Scene__
#define __glut_example__Scene__

#include "Object.h"
#include <assert.h>

class Scene : public Object
{
public:
    Scene() : Object() { _anchorPoint = point(0, 0); }
    
    // you can not set anchor point for scene manually
    virtual void setAnchorPoint(const CGPoint&) { assert(0); }
};

#endif /* defined(__glut_example__GameScene__) */
