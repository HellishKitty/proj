#include <string>
#include <iostream>
#include "steel_arm.h"


steel_arm::steel_arm() {

    this->attack = 0;
    this->accuracy = 0;
    this->attack_speed_bonus = 0;

    this->attack_range = 0;

    this->rank = 0;
    this->gear = 0;
    this->type = "steel arm";
    this->name = "null";

}


steel_arm::steel_arm(const std::string &name, const int &rank, const int &gear, const int &attack_range,
                     const int &attack, const int &accuracy, const double &attack_speed_bonus) {

    this->attack = attack;
    this->accuracy = accuracy;
    this->attack_speed_bonus = attack_speed_bonus;

    this->attack_range = attack_range;

    this->rank = rank;
    this->gear = gear;
    this->name = name;
    this->type = "steel arm";

}


steel_arm::steel_arm(const steel_arm &orig)
: steel_arm(orig.name, orig.rank, orig.gear, orig.attack_range, orig.attack, orig.accuracy, orig.attack_speed_bonus) {

    this->type = "steel arm";

}


int steel_arm::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->attack += GEAR_ATTACK * this->rank;
        this->accuracy += GEAR_ACCURACY *  this->rank;
        this->attack_speed_bonus += GEAR_ATTACK_SPEED * this->rank;
        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear << std::endl;
    }

    return this->gear;

}


std::shared_ptr<arm> steel_arm::convert_arm() {

    return std::make_shared<steel_arm>(this->name, this->rank, this->gear, this->attack_range,
            this->attack, this->accuracy, this->attack_speed_bonus);

}


void steel_arm::print() {

    std::cout << rank_map[this->rank] << " " << this->name;
    if (this->gear != 0)
        std::cout << " +" << this->gear;
    std::cout << std::endl;

    std::cout << "      attack range: " << this->attack_range << "m."<< std::endl;
    std::cout << "     attack damage: " << this->attack << std::endl;
    std::cout << "          accuracy: " << this->accuracy << std::endl;
    std::cout << "attack speed bonus: " << 100 * this->attack_speed_bonus << "%" << std::endl;

}


std::ostream &operator << (std::ostream &stream, const steel_arm & out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << "      attack range: " << out.attack_range << "m."<< std::endl;
    stream << "     attack damage: " << out.attack << std::endl;
    stream << "          accuracy: " << out.accuracy << std::endl;
    stream << "attack speed bonus: " << 100 * out.attack_speed_bonus << "%" << std::endl;

    return stream;
}
