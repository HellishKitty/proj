#ifndef _MAGIC_ARM_H
#define _MAGIC_ARM_H

#include <string>
#include <ostream>
#include "arm_abstract.h"


typedef class magic_arm : virtual public arm {

protected:

    int spell_power;
    int spell_accuracy;
    double cast_speed_bonus;

public:

    magic_arm();
    magic_arm(const std::string &name, const int &rank, const int &gear, const int &attack_range,
                 const int &spell_power, const int &spell_accuracy, const double &cast_speed_bonus);
    magic_arm(const magic_arm &orig);
    ~magic_arm() override = default;

    int gear_up() override;
    int get_spell_power() override { return this->spell_power; }
    int get_spell_accuracy() override { return this->spell_accuracy; }
    double get_cast_speed_bonus() override { return this->cast_speed_bonus; }

    void print() override;
    friend std::ostream & operator << (std::ostream & stream, const magic_arm & out);

} magic;


#endif // _MAGIC_ARM_H
