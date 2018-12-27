#ifndef _ITEMS_ABSTRACT_H
#define _ITEMS_ABSTRACT_H

#include <map>
#include <string>
#include <ostream>
#define MAX_GEAR 10


extern std::map <int, std::string>rank_map;

class item {

protected:

    int rank;
    int gear;
    std::string name;
    std::string type;

public:

    virtual ~item() = default;
    virtual int gear_up() = default;

    int get_rank() { return this->rank; }
    int get_gear() { return this->gear; }
    std::string get_name() { return this->name; }
    std::string get_type() { return this->type; }

    friend std::ostream & operator << (std::ostream & stream, const item & out) {
        return stream;
    }

};


#endif // _ITEMS_ABSTRACT_H
