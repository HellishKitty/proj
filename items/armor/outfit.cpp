#include <iostream>
#include "outfit.h"


outfit::outfit() {

    this->armor = 0;
    this->resist = 0;
    this->health = 0;
    this->evasion = 0;
    this->dispelling = 0;

    this->rank = 0;
    this->gear = 0;
    this->type = "outfit";
    this->name = "null";

}


outfit::outfit(const std::string &name, const int &rank, const int &gear, const int &armor, const int &resist,
               const int &health, const int &evasion, const int &dispelling) {

    this->armor = armor;
    this->resist = resist;
    this->health = health;
    this->evasion = evasion;
    this->dispelling = dispelling;

    this->rank = rank;
    this->gear = gear;
    this->name = name;
    this->type = "outfit";

}


outfit::outfit(const outfit &orig)
: outfit(orig.name, orig.rank, orig.gear, orig.armor, orig.resist, orig.health, orig.evasion, orig.dispelling) { }


outfit::~outfit() {

    std::cout << this->name << " destroyed" << std::endl;

}


// methods
int outfit::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->armor += 2 * GEAR_ARMOR * this->rank;
        this->resist += 2 * GEAR_RESIST * this->rank;
        this->health += 2 * GEAR_HEALTH * this->rank;
        this->evasion += 2 * GEAR_ACCURACY * this->rank;
        this->dispelling += 2 * GEAR_SPELL_ACCURACY *  this->rank;
        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear << std::endl;
    }

    return this->gear;
}


// friends
std::ostream &operator << (std::ostream &stream, const outfit &out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << "     armor: " << out.armor << std::endl;
    stream << "    resist: " << out.resist << std::endl;
    stream << "    health: " << out.health << std::endl;
    stream << "   evasion: " << out.evasion << std::endl;
    stream << "dispelling: " << out.dispelling << std::endl;

    return stream;
}
