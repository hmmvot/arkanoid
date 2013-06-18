//
//  GameObject.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__GameObject__
#define __glut_example__GameObject__

#include "Object.h"

class GameObject : public Object
{
    SYNTHESIZE(CGPoint, _velocity, velocity, setVelocity);
    
public:
    GameObject();
    
    virtual void setSize(const CGSize&);
    virtual CGSize sizeInPoints() const;
    virtual CGPoint positionInPoints() const;
    virtual CGPoint positionUnrelativeAnchorInPoints() const;
    virtual CGPoint velocityInPoints() const;
    
    virtual void visit();
};

#endif /* defined(__glut_example__GameObject__) */
