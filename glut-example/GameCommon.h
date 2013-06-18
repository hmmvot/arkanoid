//
//  GameCommon.h
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#ifndef __glut_example__GameCommon__
#define __glut_example__GameCommon__

#include "Geometry.h"

//extern const float HUDWidthInCells;
extern const CGSize gridSize;

void updateCellSize();
CGSize cellSize();

CGPoint toGrid(const CGPoint& p);
CGSize toGrid(const CGSize& p);
CGPoint toPoints(const CGPoint& p);
CGSize toPoints(const CGSize& p);

#endif /* defined(__glut_example__GameCommon__) */
