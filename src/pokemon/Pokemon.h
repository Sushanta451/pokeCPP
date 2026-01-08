#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon {
private:
    // basic info of a pokemon
    std::string name;
    int level;
    int exp;

    // stats
    int maxhp;
    int hp;
    int attack;
    int defense;
    int spa;
    int spd;
    int speed;

    // ivs
    int hp_iv;
    int attack_iv;
    int defense_iv;
    int spa_iv;
    int spd_iv;
    int speed_iv;

    // evs 
    int hp_ev;
    int attack_ev;
    int defense_ev;
    int spa_ev;
    int spd_ev;
    int speed_ev;

    // base stat
    int hp_base;
    int attack_base;
    int defense_base;
    int spa_base;
    int spd_base;
    int speed_base;

    void calc_stats();
    
    int generate_iv();

public:
    //overloading
    Pokemon(std::string pokemon_name, int pokemon_level); // wild encouters,etc..
    Pokemon(); // party
    Pokemon(const Pokemon& other); //used for trading, putting pokemon in boxes

    std::string getName() const;
    int getLevel() const;
    int getExp() const;
    
    // getters
    int getHp() const;
    int getMaxhp() const;
    int getAttack() const;
    int getDefense() const;
    int getSpa() const;
    int getSpd() const;
    int getSpeed() const;
    
    // IV getters
    int getHp_iv() const;
    int getAttack_iv() const;
    int getDefense_iv() const;
    int getSpa_iv() const;
    int getSpd_iv() const;
    int getSpeed_iv() const;
    
    // SETTERS - controlled modification
    void takeDamage(int damage);
    void heal(int amount);
    void gainExp(int amount);
    
    // Status check
    bool isFainted() const;

};

#endif