#ifndef _NECKLACE_H
#define _NECKLACE_H

#include <string>
#include <ostream>
#include "accessory_abstract.h"


class necklace : public accessory {

protected:

    double spell_power_bonus;
    int mana;

public:

    necklace();
    necklace(const std::string &name, const int &rank, const int &gear,
            const double &spell_power_bonus, const int &mana);
    necklace(const necklace &orig);
    ~necklace() override = default;

    int gear_up() override;
    int get_mana() { return this->mana; }
    double get_spell_power_bonus() { return this->spell_power_bonus; }

    std::shared_ptr<necklace> convert_necklace() override;

    void print() override;
    friend std::ostream &operator << (std::ostream &stream, const necklace &out);

};



#endif // _NECKLACE_H
