#ifndef _MAGIC_WEAPON_H
#define _MAGIC_WEAPON_H

#include <string>
#include <ostream>
#include "weapon_abstract.h"


typedef class magic_weapon : virtual public weapon {

protected:

    int spell_power;
    int spell_accuracy;
    double cast_speed_bonus;

public:

    magic_weapon();
    magic_weapon(const std::string &name, const int &rank, const int &gear, const int &attack_range,
                 const int &spell_power, const int &spell_accuracy, const double &cast_speed_bonus);
    magic_weapon(const magic_weapon &orig);

    int gear_up() override;
    int get_spell_power() { return this->spell_power; }
    int get_spell_accuracy() { return this->spell_accuracy; }
    double get_cast_speed_bonus() { return this->cast_speed_bonus; }

    friend std::ostream & operator << (std::ostream & stream, const magic_weapon & out);

} magic;


#endif // MAGIC_WEAPON_H
