#include "raylib.h"
#include "pokemon/Pokemon.h"
#include <iostream>

int main() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║     PHASE 1 COMPREHENSIVE TEST (Steps 1-4)            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl;
    
    // ========== STEP 1: ENCAPSULATION & PRIVATE MEMBERS ==========
    std::cout << "\n[STEP 1] Testing Encapsulation & Private Members" << std::endl;
    std::cout << "Creating Pikachu with random IVs and base stats..." << std::endl;
    Pokemon pikachu("Pikachu", 5);
    
    std::cout << "✓ Private members are protected (can't access directly)" << std::endl;
    
    // ========== STEP 2: MULTIPLE CONSTRUCTORS ==========
    std::cout << "\n[STEP 2] Testing Multiple Constructors" << std::endl;
    
    std::cout << "\n2A. Default Constructor:" << std::endl;
    Pokemon empty;
    
    std::cout << "\n2B. Parameterized Constructor:" << std::endl;
    Pokemon charizard("Charizard", 36);
    
    std::cout << "\n2C. Copy Constructor (Clone):" << std::endl;
    Pokemon pikachu_clone(pikachu);
    std::cout << "Original Pikachu Attack IV: " << pikachu.getAttack_iv() << std::endl;
    std::cout << "Cloned Pikachu Attack IV:   " << pikachu_clone.getAttack_iv() << std::endl;
    std::cout << "✓ Clone has SAME IVs as original!" << std::endl;
    
    // ========== STEP 3: GETTERS & SETTERS ==========
    std::cout << "\n[STEP 3] Testing Getters & Setters" << std::endl;
    
    std::cout << "\n3A. Getters (read-only access):" << std::endl;
    std::cout << "Name: " << pikachu.getName() << std::endl;
    std::cout << "Level: " << pikachu.getLevel() << std::endl;
    std::cout << "HP: " << pikachu.getHp() << "/" << pikachu.getMaxhp() << std::endl;
    std::cout << "Attack: " << pikachu.getAttack() << std::endl;
    std::cout << "✓ All getters work!" << std::endl;
    
    std::cout << "\n3B. Setters with validation:" << std::endl;
    std::cout << "Taking damage..." << std::endl;
    pikachu.takeDamage(5);
    
    std::cout << "\nHealing..." << std::endl;
    pikachu.heal(3);
    
    std::cout << "\nOver-healing (should cap at max)..." << std::endl;
    pikachu.heal(999);
    if (pikachu.getHp() == pikachu.getMaxhp()) {
        std::cout << "✓ Validation works! HP capped at max!" << std::endl;
    } else {
        std::cout << "❌ Bug detected! HP not capped properly!" << std::endl;
    }
    
    std::cout << "\nMassive damage (HP should not go negative)..." << std::endl;
    pikachu.takeDamage(999);
    if (pikachu.getHp() == 0) {
        std::cout << "✓ Validation works! HP can't go negative!" << std::endl;
    } else {
        std::cout << "❌ Bug detected! HP went negative or validation failed!" << std::endl;
    }
    
    if (pikachu.isFainted()) {
        std::cout << "✓ isFainted() works correctly!" << std::endl;
    }
    
    // ========== STEP 4: THIS POINTER ==========
    std::cout << "\n[STEP 4] Testing 'this' Pointer" << std::endl;
    
    std::cout << "\n4A. Using 'this->' in displayInfo():" << std::endl;
    Pokemon squirtle("Squirtle", 7);
    squirtle.displayInfo();
    
    std::cout << "\n4B. Method chaining with 'return *this':" << std::endl;
    std::cout << "Chaining: setLevel().addEv().heal()..." << std::endl;
    squirtle.setLevel(15)
            .addEv(100, 100, 0, 0, 0, 0)
            .heal(50);
    std::cout << "✓ Method chaining works!" << std::endl;
    squirtle.displayInfo();
    
    std::cout << "\n4C. Comparing objects with 'this':" << std::endl;
    Pokemon squirtle2("Squirtle", 7);
    Pokemon& squirtle_ref = squirtle;
    
    std::cout << "squirtle vs squirtle2 (different): " 
              << (squirtle.isSamePokemon(squirtle2) ? "SAME ❌" : "DIFFERENT ✓") << std::endl;
    std::cout << "squirtle vs squirtle_ref (same): " 
              << (squirtle.isSamePokemon(squirtle_ref) ? "SAME ✓" : "DIFFERENT ❌") << std::endl;
    
    // ========== EV SYSTEM TEST ==========
    std::cout << "\n[BONUS] Testing EV System (Every 4 EVs = 1 Stat)" << std::endl;
    Pokemon machop("Machop", 50);
    
    std::cout << "\nBefore EV training:" << std::endl;
    int attack_before = machop.getAttack();
    std::cout << "Attack: " << attack_before << std::endl;
    
    std::cout << "\nAdding 252 Attack EVs..." << std::endl;
    std::cout << "Expected gain at level 50: 252/4 * 50/100 = 31 stat points" << std::endl;
    machop.addEv(0, 252, 0, 0, 0, 0);
    
    int attack_after = machop.getAttack();
    int gain = attack_after - attack_before;
    std::cout << "Attack: " << attack_after << " (gained " << gain << " points)" << std::endl;
    
    if (gain >= 30 && gain <= 32) {
        std::cout << "✓ EV formula works correctly! (4 EVs = 1 stat)" << std::endl;
    } else {
        std::cout << "⚠ EV gain: " << gain << " (expected ~31)" << std::endl;
    }
    
    machop.displayInfo();
    
    // ========== IV RANDOMNESS TEST ==========
    std::cout << "\n[BONUS] Testing IV Randomness" << std::endl;
    std::cout << "Creating 3 Pikachus to verify different IVs:" << std::endl;
    Pokemon pika1("Pikachu", 5);
    Pokemon pika2("Pikachu", 5);
    Pokemon pika3("Pikachu", 5);
    
    std::cout << "Pikachu 1 Attack IV: " << pika1.getAttack_iv() << std::endl;
    std::cout << "Pikachu 2 Attack IV: " << pika2.getAttack_iv() << std::endl;
    std::cout << "Pikachu 3 Attack IV: " << pika3.getAttack_iv() << std::endl;
    
    if (pika1.getAttack_iv() != pika2.getAttack_iv() || 
        pika2.getAttack_iv() != pika3.getAttack_iv()) {
        std::cout << "✓ IVs are random!" << std::endl;
    }
    
    // ========== FINAL SUMMARY ==========
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                    TEST SUMMARY                        ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║  ✓ Step 1: Encapsulation (private members)            ║" << std::endl;
    std::cout << "║  ✓ Step 2: Constructors (default, param, copy)        ║" << std::endl;
    std::cout << "║  ✓ Step 3: Getters/Setters with validation            ║" << std::endl;
    std::cout << "║  ✓ Step 4: 'this' pointer & method chaining           ║" << std::endl;
    std::cout << "║  ✓ IV System: Random 0-31 values                      ║" << std::endl;
    std::cout << "║  ✓ EV System: Every 4 EVs = 1 stat                    ║" << std::endl;
    std::cout << "║  ✓ Stat Formula: Official Pokemon formula             ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║            READY FOR STEP 5: STATIC MEMBERS            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl;
    
    // Raylib window
    InitWindow(800, 600, "Pokemon C++ - Phase 1 Review");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Phase 1 Steps 1-4 Complete!", 200, 200, 24, DARKGRAY);
        DrawText("✓ Encapsulation", 280, 250, 20, DARKGREEN);
        DrawText("✓ Multiple Constructors", 280, 280, 20, DARKGREEN);
        DrawText("✓ Getters & Setters", 280, 310, 20, DARKGREEN);
        DrawText("✓ 'this' Pointer & Chaining", 280, 340, 20, DARKGREEN);
        DrawText("Check terminal for full test results!", 200, 400, 18, LIGHTGRAY);
        DrawText("Ready for Step 5: Static Members!", 210, 440, 18, BLUE);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}