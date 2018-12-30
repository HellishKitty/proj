#include <iostream>
#include "belt.h"


belt::belt() {

    this->armor = 0;
    this->resist = 0;

    this->rank = 0;
    this->gear = 0;
    this->name = "null";
    this->type = "belt";

}


belt::belt(const std::string &name, const int &rank, const int &gear,
        const int &armor, const int &resist) {

    this->type = "belt";
    this->name = name;
    this->rank = rank;
    this->gear = gear;

    this->armor = armor;
    this->resist = resist;

}


belt::belt(const belt &orig) : belt(orig.name, orig.rank, orig.gear, orig.armor, orig.resist) {

    this->type = "belt";

}


belt::~belt() {

    std::cout << this->name << " destroyed" << std::endl;

}


// methods
int belt::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->armor += GEAR_ARMOR * this->rank;
        this->resist += GEAR_RESIST * this->rank;
        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear;
    }

    return this->gear;
}


// friends
std::ostream &operator << (std::ostream &stream, const belt &out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << " outfit: " << out.armor << std::endl;
    stream << "resist: " << out.resist << std::endl;

    return stream;
}
