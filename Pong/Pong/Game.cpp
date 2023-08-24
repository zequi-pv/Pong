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

    if (rectangle1.Position.x + rectangle1.Size.x >= ball.Position.x &&
        rectangle1.Position.x <= ball.Position.x + ball.Size.x &&
        rectangle1.Position.y + rectangle1.Size.y >= ball.Position.y &&
        rectangle1.Position.y <= ball.Position.y + ball.Size.y)
    {
        std::cout << "Colisiona";
        ball.Position.x -= 10.0f * GetFrameTime();
    }

    /*
    rect1.x < rect2.x + rect2.w &&
    rect1.x + rect1.w > rect2.x &&
    rect1.y < rect2.y + rect2.h &&
    rect1.y + rect1.h > rect2.y
    */

    /*
    if (r1x + r1w >= r2x &&     // r1 right edge past r2 left
  r1x <= r2x + r2w &&       // r1 left edge past r2 right
  r1y + r1h >= r2y &&       // r1 top edge past r2 bottom
  r1y <= r2y + r2h) {       // r1 bottom edge past r2 top
    return true;
}
return false;
    */

    //if (ball.Position.x == rectangle2.Position.x)
    //{
    //    ball.Position.x -= 0.5f * GetFrameTime();
    //}

    /*
    overlapping
    if (isColliding) ball.Speed.x 
    */

    if (ball.Position.x == rectangle1.Position.x)
    {
        ball.Position.x += 0.5f * GetFrameTime();
    }
}

void close()
{
    CloseWindow();
}