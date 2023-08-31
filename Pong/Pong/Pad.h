#pragma once
#include "raylib.h"

struct Pad
{
    Vector2 Position;
    Vector2 Size;
    int score = 0;
    int minPosition;
    int maxPosition;
};

void initPad1(Pad& pad);
void initPad2(Pad& pad);