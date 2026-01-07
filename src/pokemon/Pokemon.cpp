#include "Pokemon.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 

Pokemon::Pokemon(std::string pokemon_name , int pokemon_level)
    :name(pokemon_name), level(pokemon_level)
    ,exp(0)

{
    //randomly pick iv 
    static bool seed = false;
    if(!seed){
        srand(time(0));
        seed= true;
    }

    //iv
    hp_iv = generate_iv();
    attack_iv = generate_iv();
    defense_iv = generate_iv();
    spa_iv = generate_iv();
    spd_iv = generate_iv();
    speed_iv = generate_iv();

    //ev
    hp_ev = 0;
    attack_ev =0;
    defense_ev = 0;
    spa_ev = 0;
    spd_ev = 0;
    speed_ev = 0;

    calc_stats();
    hp = maxhp;

    std::cout << "\n=== Created " << name << " (Level " << level << ") ===" << std::endl;
    std::cout << "IVs: HP=" << hp_iv << " ATK=" << attack_iv << " DEF=" << defense_iv 
              << " SpA=" << spa_iv << " SpD=" << spd_iv << " SPD=" << speed_iv << std::endl;
    std::cout << "Stats: HP=" << maxhp << " ATK=" << attack << " DEF=" << defense 
              << " SpA=" << spa << " SpD=" << spd << " SPD=" << speed << std::endl;

}
int Pokemon::generate_iv(){
   int random = rand() % 32;
    return random;
}


    
