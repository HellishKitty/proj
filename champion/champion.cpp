#include "champion.h"


void champion::set_defaults() {

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