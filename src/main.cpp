#include "raylib.h"
#include "pokemon/Pokemon.h"
#include <iostream>

int main() {
    std::cout << "\n========== PHASE 1 STEP 4: THIS POINTER ==========\n" << std::endl;
    
    // Create Pokemon
    Pokemon pikachu("Pikachu", 5);
    
    std::cout << "\n--- USING 'this->' IN displayInfo() ---" << std::endl;
    pikachu.displayInfo();
    
    std::cout << "\n--- USING 'this' WITH PARAMETER NAME CONFLICT ---" << std::endl;
    pikachu.setLevel(10);  // Parameter 'level' conflicts with member 'level'
                           // 'this->level' distinguishes them!
    pikachu.displayInfo();
    
    std::cout << "\n--- METHOD CHAINING WITH 'return *this' ---" << std::endl;
    pikachu.setLevel(25)           // Returns *this
           .addEv(4, 0, 0, 0, 0, 252)  // Chain! Returns *this again
           .addEv(0, 252, 0, 0, 0, 0); // Chain again!
    
    pikachu.displayInfo();
    
    std::cout << "\n--- COMPARING OBJECTS WITH 'this' ---" << std::endl;
    Pokemon pikachu2("Pikachu", 5);
    Pokemon& pikachu_ref = pikachu;  // Reference to same object
    
    std::cout << "pikachu vs pikachu2 (different objects): " 
              << (pikachu.isSamePokemon(pikachu2) ? "SAME" : "DIFFERENT") << std::endl;
    
    std::cout << "pikachu vs pikachu_ref (same object): " 
              << (pikachu.isSamePokemon(pikachu_ref) ? "SAME" : "DIFFERENT") << std::endl;
    
    std::cout << "\n========== DONE ==========\n" << std::endl;
    
    std::cout << "\n--- CHAINING BATTLE METHODS ---" << std::endl;
    Pokemon charizard("Charizard", 36);
    
    // Battle sequence - all chained together!
    charizard.takeDamage(20)      // Takes damage
             .heal(10)            // Heals a bit
             .takeDamage(15)      // Takes more damage
             .heal(5)             // Heals again
             .displayInfo();      // Show final state
    
    std::cout << "\n--- TRAINING + BATTLE COMBO ---" << std::endl;
    Pokemon squirtle("Squirtle", 5);
    
    // Complex chain: level up, train EVs, battle, heal!
    squirtle.setLevel(10)
            .addEv(252, 0, 0, 0, 0, 0)  // Max HP EVs
            .takeDamage(30)
            .heal(15)
            .displayInfo();
    
    // Raylib window
    InitWindow(800, 600, "Pokemon C++ - Phase 1 Step 4");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("'this' Pointer Mastered!", 240, 230, 22, DARKGRAY);
        DrawText("✓ Used this-> to access members", 210, 270, 18, DARKGREEN);
        DrawText("✓ Method chaining with return *this", 210, 300, 18, DARKGREEN);
        DrawText("✓ Resolved name conflicts", 210, 330, 18, DARKGREEN);
        DrawText("✓ Compared object addresses", 210, 360, 18, DARKGREEN);
        DrawText("Check terminal for demonstrations!", 200, 400, 18, LIGHTGRAY);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}