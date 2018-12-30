#ifndef _CHAMPION_H
#define _CHAMPION_H

#include <string>
#include <ostream>

#define DEFAULT_ATTACK_RANGE 1
#define DEFAULT_ATTACK_SPEED 1
#define DEFAULT_ATTACK 200
#define DEFAULT_SPELL_POWER 600
#define DEFAULT_ACCURACY 1000
#define DEFAULT_SPELL_ACCURACY 1000
#define DEFAULT_HEALTH 10000
#define DEFAULT_MANA 5000
#define DEFAULT_ARMOR 160
#define DEFAULT_RESIST 540
#define DEFAULT_EVASION 1000
#define DEFAULT_DISPELLING 1000


typedef class champion {

protected:
// stats
    int attack_range;
    int mana;

    int attack;
    int accuracy;
    int attack_speed;

    int spell_power;
    int spell_accuracy;
    int cast_speed;

    int health;
    int armor;
    int resist;
    int evasion;
    int dispelling;
// TODO: items

public:

    void set_defaults();
    // getters
    int get_attack_range() { return this->attack_range; }
    int get_mana() { return this->mana; }

    int get_attack() { return this->attack; }
    int get_accuracy() { return this->accuracy; }
    int get_attack_speed() { return this->attack_speed; }

    int get_spell_power() { return this->spell_power; }
    int get_spell_accuracy() { return this->spell_accuracy; }
    int get_cast_speed() { return this->cast_speed; }

    int get_health() { return this->health; }
    int get_armor() { return this->armor; }
    int get_resist() { return this->resist; }
    int get_evasion() { return this->evasion; }
    int get_dispelling() { return this->dispelling; }

} champ;


#endif // _CHAMPION_H
