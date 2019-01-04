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


void champion::equip_arm(std::shared_ptr<arm> equip) {

    if (this->_arm)
        std::cout << "arm already equipped!" << std::endl;
    else {

        this->_arm = equip;

        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.accuracy = DEFAULT_ACCURACY + equip->get_attack();
        this->_stats.attack_speed = DEFAULT_ATTACK_SPEED + equip->get_attack_speed_bonus();

        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.spell_accuracy = DEFAULT_SPELL_ACCURACY + equip->get_spell_accuracy();
        this->_stats.cast_speed = DEFAULT_ATTACK_SPEED + equip->get_cast_speed_bonus();

    }

}


void champion::equip_belt(std::shared_ptr<belt> equip) {

    if (this->_belt)
        std::cout << "belt already equipped!" << std::endl;
    else {

        this->_belt = equip;

        this->_stats.armor = DEFAULT_ARMOR + this->count_armor();
        this->_stats.resist = DEFAULT_RESIST + this->count_resist();

    }

}


void champion::equip_bracelet(std::shared_ptr<bracelet> equip) {

    if (this->_bracelet)
        std::cout << "bracelet already equipped!" << std::endl;
    else {

        this->_bracelet = equip;

        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.mana = DEFAULT_MANA + this->count_mana();

    }

}


void champion::equip_necklace(std::shared_ptr<necklace> equip) {

    if (this->_necklace)
        std::cout << "necklace already equipped!" << std::endl;
    else {

        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.mana = DEFAULT_MANA + this->count_mana();

    }

}


void champion::equip_outfit(std::shared_ptr<outfit> equip) {

    if (this->_outfit)
        std::cout << "outfit already equipped!" << std::endl;

    else {

        this->_outfit = equip;

        this->_stats.armor = DEFAULT_ARMOR + this->count_armor();
        this->_stats.resist = DEFAULT_RESIST + this->count_resist();
        this->_stats.health = DEFAULT_HEALTH + this->count_health();
        this->_stats.evasion = DEFAULT_EVASION + equip->get_evasion();
        this->_stats.dispelling = DEFAULT_DISPELLING + equip->get_dispelling();

    }

}


void champion::equip_plume(std::shared_ptr<plume> equip) {

    if (this->_plume)
        std::cout << "plume already equipped!" << std::endl;
    else {

        this->_plume = equip;

        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.health = DEFAULT_HEALTH + this->count_health();

    }

}


std::shared_ptr<arm> champion::unequip_arm() {

    std::shared_ptr<arm> ret;

    if (this->_arm) {

        ret = this->_arm;
        this->_arm = nullptr;

        this->_stats.attack_range = DEFAULT_ATTACK_RANGE;
        this->_stats.attack_speed = DEFAULT_ATTACK_SPEED;
        this->_stats.cast_speed = DEFAULT_ATTACK_SPEED;
        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.accuracy = DEFAULT_ACCURACY;
        this->_stats.spell_accuracy = DEFAULT_SPELL_ACCURACY;


    } else {

        std::cout << "no arm equipped!" << std::endl;
        ret = nullptr;

    }
    return ret;
}


std::shared_ptr<belt> champion::unequip_belt() {

    std::shared_ptr<belt> ret;

    if (this->_belt) {

        ret = this->_belt;
        this->_belt = nullptr;

        this->_stats.armor = DEFAULT_ARMOR + this->count_armor();
        this->_stats.resist = DEFAULT_RESIST + this->count_resist();

    } else {

        std::cout << "no belt equipped!" << std::endl;
        ret = nullptr;

    }

    return ret;
}


std::shared_ptr<bracelet> champion::unequip_bracelet() {

    std::shared_ptr<bracelet> ret;

    if (this->_bracelet) {

        ret = this->_bracelet;
        this->_belt = nullptr;

        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.mana = DEFAULT_MANA + this->count_mana();

    } else {

        std::cout << "no bracelet equipped!" << std::endl;
        ret = nullptr;

    }

    return ret;
}


std::shared_ptr<necklace> champion::unequip_necklace() {

    std::shared_ptr<necklace> ret;

    if (this->_necklace) {

        ret = this->_necklace;
        this->_necklace = nullptr;

        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.mana = DEFAULT_MANA + this->count_mana();

    } else {

        std::cout << "no necklace equipped!" << std::endl;
        ret = nullptr;

    }

    return ret;
}


std::shared_ptr<outfit> champion::unequip_outfit() {

    std::shared_ptr<outfit> ret;

    if (this->_outfit) {

        ret = this->_outfit;
        this->_necklace = nullptr;

        this->_stats.armor = DEFAULT_ARMOR + this->count_armor();
        this->_stats.resist = DEFAULT_RESIST + this->count_resist();
        this->_stats.health = DEFAULT_HEALTH + this->count_health();
        this->_stats.evasion = DEFAULT_EVASION;
        this->_stats.dispelling = DEFAULT_DISPELLING;

    } else {

        std::cout << "no outfit equipped!" << std::endl;
        ret = nullptr;

    }

    return ret;
}


std::shared_ptr<plume> champion::unquip_plume() {

    std::shared_ptr<plume> ret;

    if (this->_outfit) {

        ret = this->_plume;
        this->_outfit = nullptr;

        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.health = DEFAULT_HEALTH + this->count_health();

    } else {

        std::cout << "no plume equipped!" << std::endl;
        ret = nullptr;

    }

    return ret;
}


void champion::gear_up_arm() {

    if (this->_arm) {

        this->_arm->gear_up();

        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.accuracy = DEFAULT_ACCURACY + this->_arm->get_accuracy();
        this->_stats.attack_speed = DEFAULT_ATTACK_SPEED + this->_arm->get_attack_speed_bonus();

        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.spell_accuracy = DEFAULT_ACCURACY + this->_arm->get_spell_accuracy();
        this->_stats.cast_speed = DEFAULT_ATTACK_SPEED + this->_arm->get_cast_speed_bonus();

    } else
        std::cout << "no arm equipped!" << std::endl;

}


void champion::gear_up_belt() {

    if (this->_belt) {

        this->_belt->gear_up();

        this->_stats.armor = DEFAULT_ARMOR + this->count_armor();
        this->_stats.resist = DEFAULT_RESIST + this->count_resist();

    } else
        std::cout << "no belt equipped" << std::endl;

}


void champion::gear_up_bracelet() {

    if (this->_bracelet) {

        this->_bracelet->gear_up();

        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.mana = DEFAULT_MANA + this->count_mana();

    } else
        std::cout << "no bracelet equipped!" << std::endl;

}


void champion::gear_up_necklace() {

    if (this->_necklace) {

        this->_necklace->gear_up();

        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.mana = DEFAULT_MANA + this->count_mana();

    } else
        std::cout << "no necklace equipped!" << std::endl;

}


void champion::gear_up_outfit() {

    if (this->_outfit) {

        this->_outfit->gear_up();

        this->_stats.armor = DEFAULT_ARMOR + this->count_armor();
        this->_stats.resist = DEFAULT_RESIST + this->count_resist();
        this->_stats.health = DEFAULT_HEALTH + this->count_health();
        this->_stats.evasion = DEFAULT_EVASION + this->_outfit->get_evasion();
        this->_stats.dispelling = DEFAULT_DISPELLING + this->_outfit->get_dispelling();

    } else
        std::cout << "no outfit equipped!" << std::endl;

}


void champion::gear_up_plume() {

    if (this->_plume) {

        this->_plume->gear_up();

        this->_stats.attack = DEFAULT_ATTACK + this->count_attack();
        this->_stats.spell_power = DEFAULT_SPELL_POWER + this->count_spell_power();
        this->_stats.health = DEFAULT_HEALTH + this->count_health();

    } else
        std::cout << "no plume equipped!" << std::endl;

}


// friends
std::ostream &operator << (std::ostream &stream, const champion &out) {

    stream << "//---------------" << out.name << "---------------//" << std::endl;

    stream << out._stats;

    stream << "//----------------------items:" << std::endl;
    if (out._arm != nullptr)
        out._arm->print();
    else
        std::cout << "no arm equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._outfit)
        stream << *out._outfit;
    else
        stream << "no outfit equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._belt)
        stream << *out._belt;
    else
        stream << "no belt equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._bracelet)
        stream << *out._bracelet;
    else
        stream << "no bracelet equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._necklace)
        stream << *out._necklace;
    else
        stream << "no necklace equipped!" << std::endl;

    stream << "------------------------------" << std::endl;

    if (out._plume)
        stream << *out._plume;
    else
        stream << "no plume equipped!" << std::endl;


    return stream;
}
