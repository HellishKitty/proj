#ifndef _PLUME_H
#define _PLUME_H

#include <string>
#include <ostream>
#include "accessory_abstract.h"


class plume : public accessory {

protected:

    int attack;
    int health;
    int spell_power;

public:

    plume();
    plume(const std::string &name, const int &rank, const int &gear,
    const int &health, const int &attack, const int &spell_power);
    plume(const plume &orig);
    ~plume() override;

    int gear_up() override;
    int get_attack() { return this->attack; }
    int get_health() { return this->health; }
    int get_spell_power() { return this->spell_power; }

    friend std::ostream &operator << (std::ostream &stream, const plume &out);

};


#endif // _PLUME_H
