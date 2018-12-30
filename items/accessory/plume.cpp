#include <string>
#include <iostream>
#include <ostream>
#include "plume.h"


plume::plume() {

    this->attack = 0;
    this->health = 0;
    this->spell_power = 0;
    this->rank = 0;
    this->gear = 0;
    this->name = "null";
    this->type = "plume";

}


plume::plume(const std::string &name, const int &rank, const int &gear, const int &health,
             const int &attack, const int &spell_power) {

    this->type = "plume";
    this->name = name;
    this->rank = rank;
    this->gear = gear;

    this->attack = attack;
    this->health = health;
    this->spell_power = spell_power;

}


plume::plume(const plume &orig)
: plume(orig.name, orig.rank, orig.gear, orig.health, orig.attack, orig.spell_power) {

    this->type = "plume";

}


plume::~plume() {

    std::cout << this->name << " destroyed" << std::endl;

}


// methods
int plume::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->attack += GEAR_ATTACK * this->rank;
        this->spell_power += GEAR_SPELL_POWER * this->rank;
        this->health += GEAR_HEALTH * this->rank;
        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear << std::endl;
    }

    return this->gear;
}


// friends
std::ostream &operator << (std::ostream &stream, const plume &out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << "     attack: " << out.attack << std::endl;
    stream << "spell power: " << out.spell_power << std::endl;
    stream << "     health: " << out.health << std::endl;

    return stream;
}
