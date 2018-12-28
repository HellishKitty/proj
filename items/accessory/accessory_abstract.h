#ifndef _ACCESSORY_ABSTRACT_H
#define _ACCESSORY_ABSTRACT_H

#include <ostream>
#include "../items_abstract.h"


class accessory : public item {

public:

    ~accessory() override = default;

    friend std::ostream & operator << (std::ostream & stream, accessory & out) {
        return stream;
    }

};


#endif // _ACCESSORY_ABSTRACT_H
