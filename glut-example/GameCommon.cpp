//
//  GameCommon.cpp
//  glut-example
//
//  Created by Alexander Sokolenko on 17.06.13.
//  Copyright (c) 2013 Alexander Sokolenko. All rights reserved.
//

#include "GameCommon.h"
#include "Director.h"
#include <math.h>


//const float HUDWidthInCells = 8;
const CGSize gridSize = {30 /*- HUDWidthInCells */, 20};
static CGSize _cellSize = {1, 1};

void updateCellSize()
{
    CGSize screenSize = Director::getInstance().screenSize();
    float w = floorf(screenSize.width / gridSize.width);
    float h = floorf(screenSize.height / gridSize.height);
    float s = w < h ? w : h;
    _cellSize = CGSizeMake(s, s);
}

CGSize cellSize()
{
    return _cellSize;
}

CGPoint toGrid(const CGPoint& p)
{
    return point(p.x / _cellSize.width, p.y / _cellSize.height);
}

CGSize toGrid(const CGSize& s)
{
    return CGSizeMake(s.width / _cellSize.width, s.height / _cellSize.height);
}

CGPoint toPoints(const CGPoint& p)
{
    return point(p.x * _cellSize.width, p.y * _cellSize.height);
}

CGSize toPoints(const CGSize& s)
{
    return CGSizeMake(s.width * _cellSize.width, s.height * _cellSize.height);
}
