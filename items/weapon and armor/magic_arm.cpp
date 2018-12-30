#include <string>
#include <iostream>
#include "magic_arm.h"


magic_arm::magic_arm() {

    this->spell_power = 0;
    this->spell_accuracy = 0;
    this->cast_speed_bonus = 0;

    this->attack_range = 0;

    this->rank = 0;
    this->gear = 0;
    this->type = "magic arm";
    this->name = "null";

}


magic_arm::magic_arm(const std::string &name, const int &rank, const int &gear, const int &attack_range,
        const int &spell_power, const int &spell_accuracy, const double &cast_speed_bonus) {

    this->spell_power = spell_power;
    this->spell_accuracy = spell_accuracy;
    this->cast_speed_bonus = cast_speed_bonus;

    this->attack_range = attack_range;

    this->rank = rank;
    this->gear = gear;
    this->name = name;
    this->type = "magic arm";

}


magic_arm::magic_arm(const magic_arm &orig)
: magic_arm(orig.name, orig.rank, orig.gear,  orig.attack_range, orig.spell_power, orig.spell_accuracy, orig.cast_speed_bonus){

    this->type = "magic arm";

}


// methods
int magic_arm::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->spell_power += 15 * this->rank;
        this->spell_accuracy += 10 *  this->rank;
        this->cast_speed_bonus += 0.01 * this->rank;
        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear << std::endl;
    }

    return this->gear;
}


// friends
std::ostream & operator << (std::ostream & stream, const magic_arm & out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << "    attack range: " << out.attack_range << "m."<< std::endl;
    stream << "     spell power: " << out.spell_power << std::endl;
    stream << "  spell accuracy: " << out.spell_accuracy << std::endl;
    stream << "cast speed bonus: " << 100 * out.cast_speed_bonus << "%" << std::endl;

    return stream;
}
