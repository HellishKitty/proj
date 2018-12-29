#include <iostream>
#include <ostream>
#include <string>
#include "bracelet.h"


bracelet::bracelet() {

    this->attack_bonus = 0;
    this->mana = 0;

    this->rank = 0;
    this->gear = 0;
    this->name = name;
    this->type = "bracelet";

}


bracelet::bracelet(const std::string &name, const int &rank, const int &gear,
        const double &attack_bonus, const int &mana) {

    this->type = "bracelet";
    this->name = name;
    this->rank = rank;
    this->gear = gear;

    this->attack_bonus = attack_bonus;
    this->mana = mana;

}


bracelet::bracelet(const bracelet &orig)
: bracelet(orig.name, orig.rank, orig.gear, orig.attack_bonus, orig.mana) {

    this->type = "bracelet";

}


int bracelet::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->attack_bonus += this->rank * 0.01;
        this->mana += 15 * this->rank;
        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear << std::endl;
    }

    return this->gear;
}


std::ostream &operator << (std::ostream &stream, const bracelet &out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << "attack bonus: " << out.attack_bonus << std::endl;
    stream << "        mana: " << out.mana << std::endl;

    return stream;
}
