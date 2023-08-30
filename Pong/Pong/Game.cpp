#include "Game.h"
#include "raylib.h"
#include <time.h>
#include <iostream>

const int screenWidth = 800;
const int screenHeight = 450;

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

bool isColliding(Pad rectangle, Ball ball)
{
    return rectangle.Position.x + rectangle.Size.x >= ball.Position.x &&
        rectangle.Position.x <= ball.Position.x + ball.Size.x &&
        rectangle.Position.y + rectangle.Size.y >= ball.Position.y &&
        rectangle.Position.y <= ball.Position.y + ball.Size.y;
}

void Limit(Pad& rectangle)
{
    if (rectangle.Position.y <= 0)
    {
        rectangle.Position.y = 0;
    }
    if (rectangle.Position.y + screenHeight >= GetScreenHeight())
    {
        rectangle.Position.y = GetScreenHeight() - screenHeight;
    }
}

void ResetBall(int initialDirection, Ball& ball)
{
    ball.Position.x = GetScreenWidth() / 2;
    ball.Position.y = GetScreenHeight() / 2;

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

    if ((ball.Position.x >= (GetScreenWidth() - ball.Size.x)) || (ball.Position.x <= ball.Size.x)) ball.Speed.x *= -1.0f;
    if ((ball.Position.y >= (GetScreenHeight() - ball.Size.y)) || (ball.Position.y <= ball.Size.y)) ball.Speed.y *= -1.0f;
}

void init(Ball& ball, Pad& rectangle1, Pad& rectangle2, Pad& middleRectangle)
{
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
    if (IsKeyDown(KEY_W)) rectangle1.Position.y -= 120.0f * GetFrameTime();

    if (IsKeyDown(KEY_S)) rectangle1.Position.y += 120.0f * GetFrameTime();

    if (IsKeyDown(KEY_UP)) rectangle2.Position.y -= 120.0f * GetFrameTime();

    if (IsKeyDown(KEY_DOWN)) rectangle2.Position.y += 120.0f * GetFrameTime();
}

void draw(Ball& ball, Pad& rectangle1, Pad& rectangle2, Pad& middleRectangle)
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("Pong - Ezequiel Prieto", 10, 10, 20, WHITE);

    DrawText(TextFormat("%i", rectangle1.score), 10, 20, 20, WHITE);

    DrawText(TextFormat("%i", rectangle2.score), 10, 30, 20, WHITE);

    DrawRectangleV(ball.Position, ball.Size, WHITE);

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

    if ((ball.Position.x >= (GetScreenWidth() - ball.Size.x)) || (ball.Position.x <= ball.Size.x)) ball.Speed.x *= -1.0f;
    if ((ball.Position.y >= (GetScreenHeight() - ball.Size.y)) || (ball.Position.y <= ball.Size.y)) ball.Speed.y *= -1.0f;

    if (isColliding(rectangle1, ball))
    {
        ball.Position.x = rectangle1.Position.x + ball.Size.x;
        ball.Speed.x *= -1.0f;
        ball.Speed.y *= -1.0f;
    }

    if (isColliding(rectangle2, ball))
    {
        ball.Position.x = rectangle2.Position.x - ball.Size.x;
        ball.Speed.x *= -1.0f;
        ball.Speed.y *= -1.0f;
    }
    
    if (ball.Position.x + ball.Size.x / 2 >= GetScreenWidth())
    {
        rectangle2.score++;
        ResetBall(initialDirection, ball);
    }
    if (ball.Position.x - ball.Size.x / 2 <= 0)
    {
        rectangle1.score++;
        ResetBall(initialDirection, ball);
    }
}



void close()
{
    CloseWindow();
}