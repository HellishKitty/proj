#ifndef _ARM_H
#define _ARM_H

#include <ostream>
#include "../items_abstract.h"


class arm : public item {

protected:

    int attack_range;

public:

    arm() { this->attack_range = 0; }
    ~arm() override = default;

    int gear_up() override { return this->gear; }
    int get_attack_range() { return this->attack_range; }
    virtual int get_attack() { return 0; }
    virtual int get_accuracy() { return 0; }
    virtual double get_attack_speed_bonus() { return 0; }
    virtual int get_spell_power() { return 0; }
    virtual int get_spell_accuracy() { return 0; }
    virtual double get_cast_speed_bonus() { return 0; }

    virtual void print() { }
    friend std::ostream &operator << (std::ostream &stream, const arm &out) {
        return stream;
    }

};


#endif // _ARM_H
