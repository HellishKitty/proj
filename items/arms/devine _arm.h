#ifndef _HYBRID_ARM_H
#define _HYBRID_ARM_H

#include <string>
#include <ostream>
#include "steel_arm.h"
#include "magic_arm.h"


class devine_arm :  public steel_arm, magic_arm {

public:

    devine_arm();
    devine_arm(const std::string &name, const int &rank, const int &gear, const int &attack_range,
                const int &attack, const int &accuracy, const double &attack_speed_bonus,
                const int &spell_power, const int &spell_accuracy, const double &cast_speed_bonus);
    devine_arm(const devine_arm &orig);
    ~devine_arm() override = default;

    int gear_up() override;

    void print() override;
    friend std::ostream &operator << (std::ostream &stream, const devine_arm &out);

};


#endif // _HYBRID_ARM_H
