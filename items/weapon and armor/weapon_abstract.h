#ifndef _WEAPON_H
#define _WEAPON_H

#include <ostream>
#include "../items_abstract.h"


class weapon : public item {

protected:

    int attack_range;

public:

    ~weapon() override = default;

    int get_attack_range() { return this->attack_range; }

    friend std::ostream &operator << (std::ostream &stream, const weapon &out) {
        return stream;
    }

};


#endif // _WEAPON_H
