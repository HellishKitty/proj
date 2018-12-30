#ifndef _ITEMS_ABSTRACT_H
#define _ITEMS_ABSTRACT_H

#include <map>
#include <string>
#include <ostream>
#define MAX_GEAR 10
#define GEAR_ATTACK 5
#define GEAR_SPELL_POWER 15
#define GEAR_ACCURACY 10
#define GEAR_SPELL_ACCURACY 15
#define GEAR_ARMOR 4
#define GEAR_RESIST 12
#define GEAR_HEALTH 20
#define GEAR_MANA 15
#define GEAR_ATTACK_BONUS 0.01
#define GEAR_SPELL_BONUS 0.01
#define GEAR_ATTACK_SPEED 0.01
#define GEAR_CAST_SPEED 0.01


extern std::map <int, std::string>rank_map;

class item {

protected:

    int rank;
    int gear;
    std::string name;
    std::string type;

public:

    virtual ~item() = default;
    virtual int gear_up() = 0;

    int get_rank() { return this->rank; }
    int get_gear() { return this->gear; }
    std::string get_name() { return this->name; }
    std::string get_type() { return this->type; }

    friend std::ostream & operator << (std::ostream & stream, const item & out) {
        return stream;
    }

};


#endif // _ITEMS_ABSTRACT_H
