#ifndef _ITEMS_ABSTRACT_H
#define _ITEMS_ABSTRACT_H

#include <string>
#include <ostream>


class item {

protected:

    std::string name;
    std::string type;

public:

    virtual ~item() = default;
    virtual int gear_up() = default;

    std::string get_name() { return this->name; }
    std::string get_type() { return this->type; }

    friend std::ostream & operator << (std::ostream & stream, const item & out) {
        return stream;
    }

};


#endif // _ITEMS_ABSTRACT_H
