#pragma once
#include "raylib.h"

struct Pad
{
    Vector2 Position;
    Vector2 Size;
    int score = 0;
};

void initPad1(Pad& pad);
void initPad2(Pad& pad);