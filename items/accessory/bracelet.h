#ifndef _BRACELET_H
#define _BRACELET_H

#include <ostream>
#include <string>
#include "accessory_abstract.h"


class bracelet : public accessory {

protected:

    double attack_bonus;
    int mana;

public:

    bracelet();
    bracelet(const std::string &name, const int &rank, const int &gear,
            const double &attack_bonus, const int &mana);
    bracelet(const bracelet &orig);
    ~bracelet() override = default;

    int gear_up() override;
    int get_mana() { return this->mana; }
    double get_attack_bonus() { return this->attack_bonus; }

    friend std::ostream &operator << (std::ostream &stream, const bracelet &out);

};


#endif // _BRACELET_H
