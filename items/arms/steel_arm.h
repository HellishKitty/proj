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
    steel_arm(const std::string &name, const int &rank, const int &gear, const int &attack_range,
            const int &attack, const int &accuracy, const double &attack_speed_bonus);
    steel_arm(const steel_arm &orig);
    ~steel_arm() override = default;

    int gear_up() override;
    int get_attack() override { return this->attack; }
    int get_accuracy() override { return this->accuracy; }
    double get_attack_speed_bonus() override { return this->attack_speed_bonus; }
    std::shared_ptr<arm> convert_arm() override;

    void print() override;
    friend std::ostream &operator << (std::ostream &stream, const steel_arm & out);

};


#endif // _STEEL_ARM_H
