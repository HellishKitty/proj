#include <iostream>
#include <ostream>
#include <string>
#include "necklace.h"


necklace::necklace() {

    this->spell_power_bonus = 0;
    this->mana = 0;

    this->rank = 0;
    this->gear = 0;
    this->name = "null";
    this->type = "necklace";

}


necklace::necklace(const std::string &name, const int &rank, const int &gear,
        const double &spell_power_bonus, const int &mana) {

    this->type = "necklace";
    this->name = name;
    this->rank = rank;
    this->gear = gear;

    this->spell_power_bonus = spell_power_bonus;
    this->mana = mana;

}


necklace::necklace(const necklace &orig)
: necklace(orig.name, orig.rank, orig.gear, orig.spell_power_bonus, orig.mana) {

    this->type = "necklace";

}


// methods
int necklace::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->spell_power_bonus += GEAR_SPELL_POWER_BONUS * this->rank;
        this->mana += GEAR_MANA * this->rank;
        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear << std::endl;
    }

    return this->gear;
}


std::shared_ptr<necklace> necklace::convert_necklace() {

    return std::make_shared<necklace>(this->name, this->rank, this->gear,
            this->spell_power_bonus, this->mana);

}


void necklace::print() {

    std::cout << rank_map[this->rank] << " " << this->name;
    if (this->gear != 0)
        std::cout << " +" << this->gear;
    std::cout << std::endl;

    std::cout << "spell power bonus: " << 100 * this->spell_power_bonus << "%" << std::endl;
    std::cout << "             mana: " << this->mana << std::endl;

}


// friends
std::ostream &operator << (std::ostream &stream, const necklace &out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << "spell power bonus: " << 100 * out.spell_power_bonus << "%" << std::endl;
    stream << "             mana: " << out.mana << std::endl;

    return stream;
}
