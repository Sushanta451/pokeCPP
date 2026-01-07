#include "raylib.h"

int main() {
    InitWindow(800, 600, "Pokemon C++ Game");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Pokemon Game - Phase 1 Starting Soon!", 150, 280, 20, DARKGRAY);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
