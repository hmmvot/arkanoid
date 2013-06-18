//
//  Macroses.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef glut_example_Macroses_h
#define glut_example_Macroses_h

#define SYNTHESIZE(typeName, varName, getterName, setterName) \
protected: typeName varName; \
public: virtual typeName getterName() const { return varName; } \
public: virtual void setterName(typeName newVal) { varName = newVal; }

#define SYNTHESIZE_READONLY(typeName, varName, getterName) \
protected: typeName varName; \
public: virtual typeName getterName() const { return varName; }

#endif
