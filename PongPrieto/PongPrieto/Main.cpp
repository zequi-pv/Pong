#include "raylib.h"
#include <iostream>
#include <time.h>

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 rectanglePosition1 = { (float)screenWidth / 10, (float)screenHeight / 3 };
    Vector2 rectanglePosition2 = { (float)screenWidth - 100, (float)screenHeight / 3 };
    Vector2 rectangleSize = { (float)screenWidth / 30, (float)screenHeight / 4 };

    Vector2 middleRectanglePosition = { (float)screenWidth - 420, (float)screenHeight / 40 };
    Vector2 middleRectangleSize = { (float)screenWidth / 30, (float)screenHeight - 20 };

    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
    Vector2 ballSpeed = { 5.0f, 4.0f };
    int ballRadius = 20;

    SetTargetFPS(60);
    srand(time(NULL));
    int initialDirection = rand() % 2 + 1;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_UP)) rectanglePosition1.y -= 1.5f;

        if (IsKeyDown(KEY_DOWN)) rectanglePosition1.y += 1.5f;

        if (IsKeyDown(KEY_W)) rectanglePosition2.y -= 1.5f;

        if (IsKeyDown(KEY_S)) rectanglePosition2.y += 1.5f;

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Pong - Ezequiel Prieto", 10, 10, 20, WHITE);

        DrawCircleV(ballPosition, (float)ballRadius, WHITE);

        if (initialDirection == 1)
        {
            ballPosition.x += ballSpeed.x;
            ballPosition.y += ballSpeed.y;
        }
        else if (initialDirection == 2)
        {
            ballPosition.x -= ballSpeed.x;
            ballPosition.y -= ballSpeed.y;
        }

        if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) ballSpeed.x *= -1.0f;
        if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;

        if (ballPosition.x == rectanglePosition2.x)
        {
            ballPosition.x -= 0.5f;
        }

        if (ballPosition.x == rectanglePosition1.x)
        {
            ballPosition.x += 0.5f;
        }

        DrawRectangleV(rectanglePosition1, rectangleSize, WHITE);

        DrawRectangleV(rectanglePosition2, rectangleSize, WHITE);

        DrawRectangleV(middleRectanglePosition, middleRectangleSize, WHITE);

        EndDrawing();

    }


    CloseWindow();

    return 0;
}