#include "raylib.h"


int main(void)
{
   
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 rectanglePosition1 = { (float)screenWidth / 10, (float)screenHeight / 3 };
    Vector2 rectangleSize = { (float)screenWidth / 30, (float)screenHeight / 4 };
    Vector2 rectanglePosition2 = { (float)screenWidth - 100, (float)screenHeight / 3 };
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

    SetTargetFPS(60);              

    while (!WindowShouldClose())    
    {
        if (IsKeyDown(KEY_UP)) rectanglePosition1.y -= 0.5f;

        if (IsKeyDown(KEY_DOWN)) rectanglePosition1.y += 0.5f;

        if (IsKeyDown(KEY_W)) rectanglePosition2.y -= 0.5f;

        if (IsKeyDown(KEY_S)) rectanglePosition2.y += 0.5f;
      
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("move the ball with arrow keys", 10, 10, 20, WHITE);

        DrawCircleV(ballPosition , 20, WHITE);

        ballPosition.x += 0.5f;
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

        EndDrawing();
       
    }

    
    CloseWindow();        

    return 0;
}