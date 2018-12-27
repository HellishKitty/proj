#ifndef _ACCESSORY_ABSTRACT_H
#define _ACCESSORY_ABSTRACT_H

#include <ostream>
#include "../items_abstract.h"
#define MAX_AUGMENTATION 5


class accessory : public item {

    int augmentation;
    double pvp_attack_bonus;
    double  pvp_defence_bonus;

public:

    ~accessory() override = default;
    virtual int augment_up() = 0;

    int get_augmentation() { return this->augmentation; }
    double get_attack_bonus() { return this->pvp_attack_bonus; }
    double get_defence_bonus() { return this->pvp_defence_bonus; }

    friend std::ostream & operator << (std::ostream & stream, accessory & out) {
        return stream;
    }

};


#endif // _ACCESSORY_ABSTRACT_H
