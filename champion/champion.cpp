#include <iostream>
#include "champion.h"


champion::champion() {

    this->name = "null";
    this->_stats.set_defaults();
    this->set_nullptr();

}


champion::champion(const std::string &name) {

    this->name = name;
    this->_stats.set_defaults();
    this->set_nullptr();

    std::cout << "new champion created: " << this->name << std::endl;
}


champion::champion(const std::string &name, const stats &_stats, std::shared_ptr<arm> _arm,
        std::shared_ptr<outfit> _outfit, std::shared_ptr<belt> _belt, std::shared_ptr<bracelet> _bracelet,
        std::shared_ptr<necklace> _necklace, std::shared_ptr<plume> _plume) {

    this->name = name;
    this->_stats = _stats;

    this->_arm = std::make_shared<arm>(*_arm);
    this->_outfit = std::make_shared<outfit>(*_outfit);
    this->_belt = std::make_shared<belt>(*_belt);
    this->_bracelet = std::make_shared<bracelet>(*_bracelet);
    this->_necklace = std::make_shared<necklace>(*_necklace);
    this->_plume = std::make_shared<plume>(*_plume);

}


champion::champion(const std::string &name, const stats & _stats, arm *_arm, outfit *_outfit,
         belt *_belt, bracelet *_bracelet, necklace *_necklace, plume *_plume) {

    this->name = name;
    this->_stats = _stats;

    this->_arm = std::make_shared<arm>(*_arm);
    this->_outfit = std::make_shared<outfit>(*_outfit);
    this->_belt = std::make_shared<belt>(*_belt);
    this->_bracelet = std::make_shared<bracelet>(*_bracelet);
    this->_necklace = std::make_shared<necklace>(*_necklace);
    this->_plume = std::make_shared<plume>(*_plume);

}


champion::champion(const champion &orig)
: champion(orig.name, orig._stats, orig._arm, orig._outfit, orig._belt, orig._bracelet, orig._necklace, orig._plume) { }


champion::~champion() {

    std::cout << this->name << " deleted" << std::endl;

}


// methods
void champion::set_nullptr() {

    this->_arm = nullptr;
    this->_outfit = nullptr;
    this->_belt = nullptr;
    this->_bracelet = nullptr;
    this->_necklace = nullptr;
    this->_plume = nullptr;

}


int champion::count_attack() {

    int attack = 0;

    if (this->_arm)
        attack += this->_arm->get_attack();

    if (this->_plume)
        attack += this->_plume->get_attack();

    if (this->_bracelet)
        attack *=  (1.0 + this->_bracelet->get_attack_bonus());

    return attack;
}


int champion::count_spell_power() {

    int spell_power = 0;

    if (this->_arm)
        spell_power += this->_arm->get_spell_power();

    if (this->_plume)
        spell_power += this->_plume->get_spell_power();

    if (this->_necklace)
        spell_power *=  (1.0 + this->_necklace->get_spell_power_bonus());

    return spell_power;
}


int champion::count_health() {

    int health = 0;

    if (this->_outfit)
        health += this->_outfit->get_health();

    if (this->_plume)
        health += this->_plume->get_health();

    return health;
}


int champion::count_armor() {

    int armor = 0;

    if (this->_outfit)
        armor += this->_outfit->get_armor();

    if (this->_belt)
        armor += this->_belt->get_armor();

    return armor;
}


int champion::count_resist() {

    int resist = 0;

    if (this->_outfit)
        resist += this->_outfit->get_resist();

    if (this->_belt)
        resist += this->_belt->get_resist();

    return resist;
}


int champion::count_mana() {

    int mana = 0;

    if (this->_bracelet)
        mana += this->_bracelet->get_mana();

    if (this->_necklace)
        mana += this->_necklace->get_mana();

    return mana;
}


// friends
std::ostream &operator << (std::ostream &stream, const champion &out) {

    stream << "//---------------" << out.name << "---------------//" << std::endl;

    stream << out._stats;

    stream << "//----------------------items:" << std::endl;
    if (out._arm != nullptr)
        stream << out._arm;
    else
        std::cout << "no arm equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._outfit)
        stream << out._outfit;
    else
        stream << "no outfit equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._belt)
        stream << out._belt;
    else
        stream << "no belt equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._bracelet)
        stream << out._bracelet;
    else
        stream << "no bracelet equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._necklace)
        stream << out._necklace;
    else
        stream << "no necklace equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._plume)
        stream << out._plume;
    else
        stream << "no plume equipped!" << std::endl;


    return stream;
}
