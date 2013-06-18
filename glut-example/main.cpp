//
//  main.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 14.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include <GLUT/glut.h>

#include "Director.h"
#include "Game.h"


int main(int argc, char** argv)
{
    // init GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(300, 200);
    
    // create window
    glutCreateWindow("Arkanoid");
    
    // bind callbacks
    glutDisplayFunc(Director::display);
    glutReshapeFunc(Director::reshape);
    glutTimerFunc(0, Director::timer, 0);
    glutSpecialFunc(Director::keyDown);
    glutSpecialUpFunc(Director::keyUp);
    glutKeyboardFunc(Director::keyDown);
    glutKeyboardUpFunc(Director::keyUp);
    
    // run game scene
    Game game;
    Director::getInstance().run(&game);
    
    // start main loop
    glutMainLoop();
    
    return 0;
}
