//
//  Label.h
//  glut-example
//
//  Created by Alexander Sokolenko on 18.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Label__
#define __glut_example__Label__

#include "Object.h"
#include <string>

class Label : public Object
{
protected:
    std::string _string;
    
public:
    Label(const std::string& string);
    
    void setString(const std::string&);
    virtual void draw();
};

#endif /* defined(__glut_example__Label__) */
