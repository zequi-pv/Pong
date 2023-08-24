#pragma once
#include "raylib.h"
#include "Ball.h"
#include "Pad.h"

void game();
void init(Ball& ball, Pad& rectangle1, Pad& rectangle2, Pad& middleRectangle);
void inputs(Pad& rectangle1, Pad& rectangle2);
void draw(Ball& ball, Pad& rectangle1, Pad& rectangle2, Pad& middleRectangle);
void update(Ball& ball, Pad& rectangle1, Pad& rectangle2, int initialDirection);
void close();