//
//  Director.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__Director__
#define __glut_example__Director__

#include "Macroses.h"
#include "Geometry.h"
#include <OpenGL/OpenGL.h>

class Scene;
class Director
{
private:
    static Director DirectorInstance;
    Director();
    Director(const Director&) {};
    Director& operator=(const Director&) {return DirectorInstance;}
    
    SYNTHESIZE_READONLY(CGSize, _screenSize, screenSize);
    Scene *currentScene;

public:
    static Director& getInstance();
    
    static void reshape(GLsizei width, GLsizei height);
    static void display();
    static void timer(int timerId);
    static void keyDown(int key, int x, int y);
    static void keyUp(int key, int x, int y);
    static void keyDown(unsigned char key, int x, int y);
    static void keyUp(unsigned char key, int x, int y);
    
    void run(Scene *scene);
    
    void visitScene();
    void update(float dt);
    void keyboard(int key, bool isDown);
};

#endif /* defined(__glut_example__Director__) */
