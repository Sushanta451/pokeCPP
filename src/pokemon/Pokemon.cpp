#include "Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Pokemon::Pokemon(std::string pokemon_name, int pokemon_level) 
    : name(pokemon_name),
      level(pokemon_level),
      exp(0)
{
    // Seed random
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    
    // IVs 
    hp_iv = generate_iv();
    attack_iv = generate_iv();
    defense_iv = generate_iv();
    spa_iv = generate_iv();
    spd_iv = generate_iv();
    speed_iv = generate_iv();
    
    // EVs
    hp_ev = 0;
    attack_ev = 0;
    defense_ev = 0;
    spa_ev = 0;
    spd_ev = 0;
    speed_ev = 0;
    
    // Set base stats (same for all Pokemon for now)
    hp_base = 45;
    attack_base = 49;
    defense_base = 49;
    spa_base = 65;
    spd_base = 65;
    speed_base = 45;
    
    // Calculate stats
    calc_stats();
    
    // Set current HP to max
    hp = maxhp;
    
    std::cout << "\n=== Created " << name << " (Level " << level << ") ===" << std::endl;
    std::cout << "IVs: HP=" << hp_iv << " ATK=" << attack_iv << " DEF=" << defense_iv 
              << " SpA=" << spa_iv << " SpD=" << spd_iv << " SPD=" << speed_iv << std::endl;
    std::cout << "Stats: HP=" << maxhp << " ATK=" << attack << " DEF=" << defense 
              << " SpA=" << spa << " SpD=" << spd << " SPD=" << speed << std::endl;
}

int Pokemon::generate_iv() {
    return rand() % 32;
}

// Calculate stats using Pokemon formula
void Pokemon::calc_stats() {
    maxhp = ((2 * hp_base + hp_iv + hp_ev / 4) * level / 100) + level + 10;
    
    attack = ((2 * attack_base + attack_iv + attack_ev / 4) * level / 100) + 5;
    defense = ((2 * defense_base + defense_iv + defense_ev / 4) * level / 100) + 5;
    spa = ((2 * spa_base + spa_iv + spa_ev / 4) * level / 100) + 5;
    spd = ((2 * spd_base + spd_iv + spd_ev / 4) * level / 100) + 5;
    speed = ((2 * speed_base + speed_iv + speed_ev / 4) * level / 100) + 5;
}