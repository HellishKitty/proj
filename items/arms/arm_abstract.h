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

    int gear_up() override { return 0; }
    int get_attack_range() { return this->attack_range; }

    friend std::ostream &operator << (std::ostream &stream, const arm &out) {
        return stream;
    }

};


#endif // _ARM_H
