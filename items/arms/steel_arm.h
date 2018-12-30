#ifndef _STEEL_ARM_H
#define _STEEL_ARM_H

#include <string>
#include <ostream>
#include "arm_abstract.h"


class steel_arm : virtual public arm {

protected:

    int attack;
    int accuracy;
    double attack_speed_bonus;

public:

    steel_arm();
    steel_arm(const std::string &name, const int &rank, const int &gera, const int &attack_range,
            const int &attack, const int &accuracy, const double &attack_speed_bonus);
    steel_arm(const steel_arm &orig);
    ~steel_arm() override;

    int gear_up() override;
    int get_attack() { return this->attack; }
    int get_accuracy() { return this->accuracy; }
    double get_attack_speed_bonus() { return this->attack_speed_bonus; }

    friend std::ostream &operator << (std::ostream &stream, const steel_arm & out);

};


#endif // _STEEL_ARM_H
