#include "Ball.h"

void initBall(Ball& ball)
{
    ball.Position = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    ball.Speed = { 500.0f, 400.0f };
    ball.Radius = 20;
}