#include <iostream>
#include <ostream>
#include "champ_stats.h"
#include "champion.h"


void stats::set_defaults() {

    this->attack_range = DEFAULT_ATTACK_RANGE;
    this->mana = DEFAULT_MANA;

    this->attack = DEFAULT_ATTACK;
    this->accuracy = DEFAULT_ACCURACY;
    this->attack_speed = DEFAULT_ATTACK_SPEED;

    this->spell_power = DEFAULT_SPELL_POWER;
    this->spell_accuracy = DEFAULT_SPELL_ACCURACY;
    this->cast_speed = DEFAULT_ATTACK_SPEED;

    this->health = DEFAULT_HEALTH;
    this->armor = DEFAULT_ARMOR;
    this->resist = DEFAULT_RESIST;
    this->evasion = DEFAULT_EVASION;
    this->dispelling = DEFAULT_DISPELLING;

}


std::ostream &operator << (std::ostream &stream, const stats &out) {

    stream << "//----------------------stats:" << std::endl;
    stream << "  attack range: " << out.attack_range << std::endl;

    stream << "        attack: " << out.attack << std::endl;
    stream << "      accuracy: " << out.accuracy << std::endl;
    stream << "  attack speed: " << out.attack_speed * 100 << "%" << std::endl;

    stream << "   spell power: " << out.spell_power << std::endl;
    stream << "spell accuracy: " << out.spell_accuracy << std::endl;
    stream << "    cast speed: " << out.cast_speed * 100 << "%" << std::endl;

    stream << "        health: " << out.health << std::endl;
    stream << "         armor: " << out.armor << std::endl;
    stream << "        resist: " << out.resist << std::endl;
    stream << "       evasion: " << out.evasion << std::endl;
    stream << "    dispelling: " << out.dispelling << std::endl;

    return stream;
}
