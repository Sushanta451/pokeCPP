#include "Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


//wild encouters
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
    
    // iv
    hp_iv = generate_iv();
    attack_iv = generate_iv();
    defense_iv = generate_iv();
    spa_iv = generate_iv();
    spd_iv = generate_iv();
    speed_iv = generate_iv();
    
    // ev
    hp_ev = 0;
    attack_ev = 0;
    defense_ev = 0;
    spa_ev = 0;
    spd_ev = 0;
    speed_ev = 0;
    
    //  base stat
    hp_base = 45;
    attack_base = 49;
    defense_base = 49;
    spa_base = 65;
    spd_base = 65;
    speed_base = 45;
    
    // Calculate stats
    calc_stats();
    
    hp = maxhp;
    
    std::cout << "\n=== Created " << name << " (Level " << level << ") ===" << std::endl;
    std::cout << "IVs: HP=" << hp_iv << " ATK=" << attack_iv << " DEF=" << defense_iv  << " SpA=" << spa_iv << " SpD=" << spd_iv << " SPD=" << speed_iv << std::endl;
    std::cout << "Stats: HP=" << maxhp << " ATK=" << attack << " DEF=" << defense << " SpA=" << spa << " SpD=" << spd << " SPD=" << speed << std::endl;
}

//trading
Pokemon::Pokemon(const Pokemon& other)
    : name(other.name),
      level(other.level),
      exp(other.exp)
    
    {
        //ivs

        hp_iv = other.hp_iv;
        attack_iv = other.attack_iv;
        defense_iv = other.defense_iv;
        spa_iv = other.spa_iv;
        spd_iv = other.spd_iv;
        speed_iv = other.speed_iv;


        //ev

        hp_ev = other.hp_ev;
        attack_ev = other.attack_ev;
        defense_ev = other.defense_ev;
        spa_ev = other.spa_ev;
        spd_ev = other.spd_ev;
        speed_ev = other.speed_ev;

        //base

        hp_base = other.hp_base;
        attack_base = other.attack_base;
        defense_base = other.defense_base;
        spa_base = other.spa_base;
        spd_base = other.spd_base;
        speed_base = other.speed_base;

        calc_stats();

        hp = other.hp;

        std::cout << "Cloned Pokemon: " << name << " with SAME IVs!" << std::endl;
        std::cout << "  Original IVs: HP=" << other.hp_iv << " ATK=" << other.attack_iv << std::endl;
        std::cout << "  Cloned IVs:   HP=" << hp_iv << " ATK=" << attack_iv << std::endl;


}

// Default constructor
Pokemon::Pokemon() 
    : name("MissingNo"),
      level(1),
      exp(0)
{
    std::cout << "[Default Constructor] Creating unknown Pokemon..." << std::endl;
    
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    
    // Generate IVs
    hp_iv = generate_iv();
    attack_iv = generate_iv();
    defense_iv = generate_iv();
    spa_iv = generate_iv();
    spd_iv = generate_iv();
    speed_iv = generate_iv();
    
    // Initialize EVs to 0
    hp_ev = 0;
    attack_ev = 0;
    defense_ev = 0;
    spa_ev = 0;
    spd_ev = 0;
    speed_ev = 0;
    
    // Set base stats
    hp_base = 45;
    attack_base = 49;
    defense_base = 49;
    spa_base = 65;
    spd_base = 65;
    speed_base = 45;
    
    calc_stats();
    hp = maxhp;
    
    std::cout << "Created default Pokemon: " << name << " (Level " << level << ")" << std::endl;
}

int Pokemon::generate_iv() {
    return rand() % 32;
}

void Pokemon::calc_stats() {
    maxhp = ((2 * hp_base + hp_iv + hp_ev / 4) * level / 100) + level + 10;
    attack = ((2 * attack_base + attack_iv + attack_ev / 4) * level / 100) + 5;
    defense = ((2 * defense_base + defense_iv + defense_ev / 4) * level / 100) + 5;
    spa = ((2 * spa_base + spa_iv + spa_ev / 4) * level / 100) + 5;
    spd = ((2 * spd_base + spd_iv + spd_ev / 4) * level / 100) + 5;
    speed = ((2 * speed_base + speed_iv + speed_ev / 4) * level / 100) + 5;
}

//getters

std::string Pokemon::getName() const{
    return name;
}

int Pokemon::getLevel() const{
    return level;
}
int Pokemon::getExp() const{
    return exp;
}

int Pokemon::getHp() const{
    return hp;
}

//stats getters 

int Pokemon::getMaxhp() const{
    return maxhp;
}
int Pokemon::getAttack() const{
    return attack;
}
int Pokemon::getDefense() const{
    return defense;
}
int Pokemon::getSpa() const{
    return spa;
}
int Pokemon::getSpd() const{
    return spd;
}
int Pokemon::getSpeed() const{
    return speed;
}

//iv getters

int Pokemon::getHp_iv() const{
    return hp_iv;
}
int Pokemon::getAttack_iv() const{
    return attack_iv;
}
int Pokemon::getDefense_iv() const{
    return defense_iv;
}
int Pokemon::getSpa_iv() const{
    return spa_iv;
}
int Pokemon::getSpd_iv() const{
    return spd_iv;
}
int Pokemon::getSpeed_iv() const{
    return speed_iv;
}

//setter

void Pokemon::takeDamage(int damage){
    hp -= damage;
    if( damage > hp){
        hp = 0;
    }
    std::cout << name << "HP" << hp << "/" << maxhp << std::endl;
    if(hp == 0){
        std::cout << name << " has fainted" << std::endl;
    }
}

void Pokemon::heal(int amount){
    hp += amount;
    if(amount  > maxhp){
        hp = maxhp;
    }
    std::cout << name << " was healed: " << amount << " hp." << std::endl; 
}
void Pokemon::gainExp(int amount){
    exp+= amount;
    std::cout << name << " ganined " << amount << " exp " << std::endl;
}

bool Pokemon::isFainted() const{
    if(hp == 0){
        return true;
    }
    else{
        return false;
    }
}
