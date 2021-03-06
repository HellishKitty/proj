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


// methods
int bracelet::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->attack_bonus += GEAR_ATTACK_BONUS * 0.01;
        this->mana += GEAR_MANA * this->rank;
        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear << std::endl;
    }

    return this->gear;
}


std::shared_ptr<bracelet> bracelet::convert_bracelet() {

    return std::make_shared<bracelet>(this->name, this->rank, this->gear,
            this->attack_bonus, this->mana);

}


void bracelet::print() {

    std::cout << rank_map[this->rank] << " " << this->name;
    if (this->gear != 0)
        std::cout << " +" << this->gear;
    std::cout << std::endl;

    std::cout << "attack bonus: " << this->attack_bonus << std::endl;
    std::cout << "        mana: " << this->mana << std::endl;

}


// friends
std::ostream &operator << (std::ostream &stream, const bracelet &out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << "attack bonus: " << out.attack_bonus << std::endl;
    stream << "        mana: " << out.mana << std::endl;

    return stream;
}
