#include "raylib.h"
#include "pokemon/Pokemon.h"
#include <iostream>

int main() {
    std::cout << "\n========== PHASE 1 STEP 3: GETTERS & SETTERS ==========\n" << std::endl;
    
    // Create a Pokemon
    Pokemon pikachu("Pikachu", 5);
    
    std::cout << "\n--- TESTING GETTERS ---" << std::endl;
    std::cout << "Name: " << pikachu.getName() << std::endl;
    std::cout << "Level: " << pikachu.getLevel() << std::endl;
    std::cout << "HP: " << pikachu.getHp() << "/" << pikachu.getMaxhp() << std::endl;
    std::cout << "Attack: " << pikachu.getAttack() << std::endl;
    std::cout << "Defense: " << pikachu.getDefense() << std::endl;
    std::cout << "Speed: " << pikachu.getSpeed() << std::endl;
    
    std::cout << "\n--- TESTING IVs ---" << std::endl;
    std::cout << "HP IV: " << pikachu.getHp_iv() << std::endl;
    std::cout << "Attack IV: " << pikachu.getAttack_iv() << std::endl;
    std::cout << "Speed IV: " << pikachu.getSpeed_iv() << std::endl;
    
    std::cout << "\n--- TESTING DAMAGE ---" << std::endl;
    pikachu.takeDamage(5);
    pikachu.takeDamage(3);
    
    std::cout << "\n--- TESTING HEAL ---" << std::endl;
    pikachu.heal(4);
    
    std::cout << "\n--- TESTING OVER-HEAL (should cap at max) ---" << std::endl;
    pikachu.heal(100);  // Should only heal to max HP!
    
    std::cout << "\n--- TESTING FAINT ---" << std::endl;
    pikachu.takeDamage(999);  // Massive damage!
    std::cout << "Is fainted? " << (pikachu.isFainted() ? "Yes" : "No") << std::endl;
    
    std::cout << "\n========== DONE ==========\n" << std::endl;
    
    // Raylib window
    InitWindow(800, 600, "Pokemon C++ - Phase 1 Step 3");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Getters & Setters Tested!", 230, 250, 22, DARKGRAY);
        DrawText("✓ Read Pokemon stats (getters)", 220, 290, 18, DARKGREEN);
        DrawText("✓ Modify HP safely (setters)", 220, 320, 18, DARKGREEN);
        DrawText("✓ Validation (HP never negative!)", 220, 350, 18, DARKGREEN);
        DrawText("Check terminal for test results!", 220, 390, 18, LIGHTGRAY);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}