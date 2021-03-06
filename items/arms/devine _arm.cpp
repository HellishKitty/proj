#include <iostream>
#include "devine _arm.h"


devine_arm::devine_arm() {

    this->attack = 0;
    this->accuracy = 0;
    this->attack_speed_bonus = 0;

    this->spell_power = 0;
    this->spell_accuracy = 0;
    this->cast_speed_bonus = 0;

    this->attack_range = 0;
    this->rank = 0;
    this->gear = 0;
    this->name = "null";
    this->type = "divine arm";

}


devine_arm::devine_arm(const std::string &name, const int &rank, const int &gear, const int &attack_range,
                       const int &attack, const int &accuracy, const double &attack_speed_bonus, const int &spell_power,
                       const int &spell_accuracy, const double &cast_speed_bonus) {

    this->attack = attack;
    this->accuracy = accuracy;
    this->attack_speed_bonus = attack_speed_bonus;

    this->spell_power = spell_power;
    this->spell_accuracy = spell_accuracy;
    this->cast_speed_bonus = cast_speed_bonus;

    this->attack_range = attack_range;
    this->rank = rank;
    this->gear = gear;
    this->name = name;
    this->type = "divine arm";

}


devine_arm::devine_arm(const devine_arm &orig)
: devine_arm(orig.name, orig.rank, orig.gear, orig.attack_range, orig.attack, orig.accuracy, orig.attack_speed_bonus,
orig.spell_power, orig.spell_accuracy, orig.cast_speed_bonus) { }


// methods
int devine_arm::gear_up() {

    if (this->gear >= MAX_GEAR)
        std::cout << this->name << " is fully geared!" << std::endl;
    else {

        this->attack += GEAR_ATTACK * this->rank;
        this->accuracy += GEAR_ACCURACY *  this->rank;
        this->attack_speed_bonus += GEAR_ATTACK_SPEED * this->rank;

        this->spell_power += GEAR_SPELL_POWER * this->rank;
        this->spell_accuracy += GEAR_SPELL_ACCURACY *  this->rank;
        this->cast_speed_bonus += GEAR_CAST_SPEED * this->rank;

        this->gear ++;

        std::cout << this->name << " geared to +" << this->gear << std::endl;
    }

    return this->gear;

}


std::shared_ptr<arm> devine_arm::convert_arm() {

    return std::make_shared<devine_arm>(this->name, this->rank, this->gear, this->attack_range,
            this->attack, this->accuracy, this->attack_speed_bonus,
            this->spell_power, this->spell_accuracy, this->cast_speed_bonus);

}


void devine_arm::print() {

    std::cout << rank_map[this->rank] << " " << this->name;
    if (this->gear != 0)
        std::cout << " +" << this->gear;
    std::cout << std::endl;

    std::cout << "      attack range: " << this->attack_range << "m."<< std::endl;

    std::cout << "     attack damage: " << this->attack << std::endl;
    std::cout << "          accuracy: " << this->accuracy << std::endl;
    std::cout << "attack speed bonus: " << 100 * this->attack_speed_bonus << "%" << std::endl;

    std::cout << "       spell power: " << this->spell_power << std::endl;
    std::cout << "    spell accuracy: " << this->spell_accuracy << std::endl;
    std::cout << "  cast speed bonus: " << 100 * this->cast_speed_bonus << "%" << std::endl;

}


// friends
std::ostream &operator << (std::ostream &stream, const devine_arm &out) {

    stream << rank_map[out.rank] << " " << out.name;
    if (out.gear != 0)
        stream << " +" << out.gear;
    stream << std::endl;

    stream << "      attack range: " << out.attack_range << "m."<< std::endl;

    stream << "     attack damage: " << out.attack << std::endl;
    stream << "          accuracy: " << out.accuracy << std::endl;
    stream << "attack speed bonus: " << 100 * out.attack_speed_bonus << "%" << std::endl;

    stream << "       spell power: " << out.spell_power << std::endl;
    stream << "    spell accuracy: " << out.spell_accuracy << std::endl;
    stream << "  cast speed bonus: " << 100 * out.cast_speed_bonus << "%" << std::endl;

    return stream;
}
