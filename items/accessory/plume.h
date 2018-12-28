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
    ~plume() override = default;

    int gear_up() override;

    friend std::ostream &operator << (std::ostream &stream, const plume &out);

};


#endif // _PLUME_H
