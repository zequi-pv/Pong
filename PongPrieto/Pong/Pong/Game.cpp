#include "Game.h"
#include "raylib.h"
#include <time.h>
#include <iostream>

void game()
{
    Ball ball;
    Pad rectangle1;
    Pad rectangle2;
    Pad middleRectangle;

    init(ball, rectangle1, rectangle2, middleRectangle);

    srand(time(NULL));
    int initialDirection = rand() % 2 + 1;

    while (!WindowShouldClose())
    {
        inputs(rectangle1, rectangle2);

        update(ball, rectangle1, rectangle2, initialDirection);

        draw(ball, rectangle1, rectangle2, middleRectangle);
    }

    close();
}

void init(Ball& ball, Pad& rectangle1, Pad& rectangle2, Pad& middleRectangle)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    initBall(ball);

    initPad1(rectangle1);

    initPad2(rectangle2);

    middleRectangle.Position = { (float)screenWidth - 420, (float)screenHeight / 40 };
    middleRectangle.Size = { (float)screenWidth / 30, (float)screenHeight - 20 };

    //SetTargetFPS(60);
}

void inputs(Pad& rectangle1, Pad& rectangle2)
{
    if (IsKeyDown(KEY_UP)) rectangle1.Position.y -= 100.5f * GetFrameTime();

    if (IsKeyDown(KEY_DOWN)) rectangle1.Position.y += 100.5f * GetFrameTime();

    if (IsKeyDown(KEY_W)) rectangle2.Position.y -= 100.5f * GetFrameTime();

    if (IsKeyDown(KEY_S)) rectangle2.Position.y += 100.5f * GetFrameTime();
}

void draw(Ball& ball, Pad& rectangle1, Pad& rectangle2, Pad& middleRectangle)
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("Pong - Ezequiel Prieto", 10, 10, 20, WHITE);

    DrawCircleV(ball.Position, (float)ball.Radius, WHITE);

    DrawRectangleV(rectangle1.Position, rectangle1.Size, WHITE);

    DrawRectangleV(rectangle2.Position, rectangle2.Size, WHITE);

    DrawRectangleV(middleRectangle.Position, middleRectangle.Size, WHITE);

    EndDrawing();
}

void update(Ball& ball, Pad& rectangle1, Pad& rectangle2, int initialDirection)
{
    if (initialDirection == 1)
    {
        ball.Position.x += ball.Speed.x * GetFrameTime();
        ball.Position.y += ball.Speed.y * GetFrameTime();
    }
    else if (initialDirection == 2)
    {
        ball.Position.x -= ball.Speed.x * GetFrameTime();
        ball.Position.y -= ball.Speed.y * GetFrameTime();
    }

    if ((ball.Position.x >= (GetScreenWidth() - ball.Radius)) || (ball.Position.x <= ball.Radius)) ball.Speed.x *= -1.0f;
    if ((ball.Position.y >= (GetScreenHeight() - ball.Radius)) || (ball.Position.y <= ball.Radius)) ball.Speed.y *= -1.0f;

    if (ball.Position.x == rectangle2.Position.x)
    {
        ball.Position.x -= 0.5f * GetFrameTime();
    }

    if (ball.Position.x == rectangle1.Position.x)
    {
        ball.Position.x += 0.5f * GetFrameTime();
    }
}

void close()
{
    CloseWindow();
}