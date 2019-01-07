#ifndef _ITEMS_ABSTRACT_H
#define _ITEMS_ABSTRACT_H

#include <map>
#include <memory>
#include <string>
#include <ostream>
#define MAX_GEAR 10
#define GEAR_ATTACK 5
#define GEAR_SPELL_POWER 15
#define GEAR_ACCURACY 10
#define GEAR_SPELL_ACCURACY 15
#define GEAR_ARMOR 4
#define GEAR_RESIST 12
#define GEAR_HEALTH 40
#define GEAR_MANA 15
#define GEAR_ATTACK_BONUS 0.01
#define GEAR_SPELL_POWER_BONUS 0.01
#define GEAR_ATTACK_SPEED 0.01
#define GEAR_CAST_SPEED 0.01

class arm;
class outfit;
class belt;
class bracelet;
class necklace;
class plume;

extern std::map <int, std::string>rank_map;
extern std::map <std::string, int> item_type_map;

class item {

protected:

    int rank;
    int gear;
    std::string name;
    std::string type;

public:

    virtual ~item();
    virtual int gear_up() { return 0; }
    virtual std::shared_ptr<arm> convert_arm() { return nullptr; }
    virtual std::shared_ptr<outfit> convert_outfit() { return nullptr; }
    virtual std::shared_ptr<belt> convert_belt() { return nullptr; }
    virtual std::shared_ptr<bracelet> convert_bracelet() { return nullptr; }
    virtual std::shared_ptr<necklace> convert_necklace() { return nullptr; }
    virtual std::shared_ptr<plume> convert_plume() { return nullptr; }

    int get_rank() { return this->rank; }
    int get_gear() { return this->gear; }
    std::string get_name() { return this->name; }
    std::string get_type() { return this->type; }

    virtual void print() { };
    friend std::ostream & operator << (std::ostream & stream, const item & out) {
        return stream;
    }

};


#endif // _ITEMS_ABSTRACT_H
