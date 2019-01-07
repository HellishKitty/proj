#ifndef _ARMOR_H
#define _ARMOR_H

#include <string>
#include <ostream>
#include "../items_abstract.h"


class outfit : public item {

protected:

    int armor;
    int resist;
    int health;
    int evasion;
    int dispelling;

public:

    outfit();
    outfit(const std::string &name, const int &rank, const int &gear,
            const int &armor, const int &resist, const int &health, const int &evasion, const int &dispelling);
    outfit(const outfit &orig);
    ~outfit() override = default;

    int gear_up() override;
    int get_armor() { return this->armor; }
    int get_resist() { return this->resist; }
    int get_health() { return this->health; }
    int get_evasion() { return this->evasion; }
    int get_dispelling() { return this->dispelling; }

    std::shared_ptr<outfit> convert_outfit();

    void print() override;
    friend std::ostream &operator << (std::ostream &stream, const outfit &out);

};


#endif // _ARMOR_H
