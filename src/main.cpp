#include "raylib.h"
#include "pokemon/Pokemon.h"

int main() {
    
    Pokemon pikachu("Pikachu", 5);
    Pokemon charizard("Charizard", 36);

    InitWindow(800, 600, "Pokemon C++ - Phase 1 Step 1");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Pokemon Created with IVs!", 220, 250, 20, DARKGRAY);
        DrawText("Check terminal for stats!", 230, 290, 20, LIGHTGRAY);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}