#ifndef _BELT_H
#define _BELT_H

#include <string>
#include <ostream>
#include "accessory_abstract.h"


class belt : public accessory {

protected:

    int armor;
    int resist;

public:

    belt();
    belt(const std::string &name, const int &rank, const int &gear,
            const int &armor, const int &resist);
    belt(const belt &orig);
    ~belt() override = default;

    int gear_up() override;

    friend std::ostream &operator << (std::ostream &stream, const belt &out);

};



#endif // _BELT_H
