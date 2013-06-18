//
//  Platform.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Platform__
#define __glut_example__Platform__

#include "GameObject.h"

class Platform : public GameObject
{
public:
    Platform();
    
    virtual void draw();
};

#endif /* defined(__glut_example__Platform__) */
