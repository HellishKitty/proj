#ifndef _CHAMP_STATS_H
#define _CHAMP_STATS_H

#include <ostream>
//#include "champion.h"


class stats {

public:

    int attack_range;
    int mana;

    int attack;
    int accuracy;
    double attack_speed;

    int spell_power;
    int spell_accuracy;
    double cast_speed;

    int health;
    int armor;
    int resist;
    int evasion;
    int dispelling;

// methods
/*
    int get_attack_range() { return this->attack_range; }
    int get_mana() { return this->mana; }
    int get_attack() { return this->attack; }

    int get_accuracy() { return this->accuracy; }
    double get_attack_speed() { return this->attack_speed; }
    int get_spell_power() { return this->spell_power; }

    int get_spell_accuracy() { return this->spell_accuracy; }
    double get_cast_speed() { return this->cast_speed; }
    int get_health() { return this->health; }

    int get_armor() { return this->armor; }
    int get_resist() { return this->resist; }
    int get_evasion() { return this->evasion; }
    int get_dispelling() { return this->dispelling; }
*/
// other methods
    void set_defaults();

    friend std::ostream &operator << (std::ostream &stream, const stats &out);

};


#endif // _CHAMP_STATS_H
