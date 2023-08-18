#pragma once
#include "raylib.h"

struct Ball
{
    Vector2 Position;
    Vector2 Speed;
    int Radius;
};

void initBall(Ball& ball);