#ifndef _CHAMPION_H
#define _CHAMPION_H

#include <string>
#include <memory>
#include <ostream>
#include "champ_stats.h"
#include "../items/accessory/belt.h"
#include "../items/accessory/bracelet.h"
#include "../items/accessory/plume.h"
#include "../items/armor/outfit.h"
#include "../items/arms/steel_arm.h"
#include "../items/arms/magic_arm.h"
#include "../items/arms/devine _arm.h"
#include "../items/accessory/necklace.h"

#define DEFAULT_ATTACK_RANGE 1
#define DEFAULT_ATTACK_SPEED 1
#define DEFAULT_ATTACK 200
#define DEFAULT_SPELL_POWER 600
#define DEFAULT_ACCURACY 1000
#define DEFAULT_SPELL_ACCURACY 1000
#define DEFAULT_HEALTH 10000
#define DEFAULT_MANA 5000
#define DEFAULT_ARMOR 160
#define DEFAULT_RESIST 540
#define DEFAULT_EVASION 1000
#define DEFAULT_DISPELLING 1000


typedef class champion {

protected:

    std::string name;

// items
    std::shared_ptr<arm> _arm;
    std::shared_ptr<outfit> _outfit;
    std::shared_ptr<belt> _belt;
    std::shared_ptr<bracelet> _bracelet;
    std::shared_ptr<necklace> _necklace;
    std::shared_ptr<plume> _plume;

public:
    stats _stats;

    champion(); // default constructor
    explicit champion(const std::string &name);
    champion(const std::string &name, const stats & _stats, std::shared_ptr<arm> _arm, std::shared_ptr<outfit> _outfit,
            std::shared_ptr<belt> _belt, std::shared_ptr<bracelet> _bracelet,std::shared_ptr<necklace> _necklace, std::shared_ptr<plume> _plume);
    champion(const std::string &name, const stats & _stats, arm *_arm, outfit *_outfit,
             belt *_belt, bracelet *_bracelet, necklace *_necklace, plume *_plume);
    champion(const champion &orig);
    ~champion();

    // methods
    void set_nullptr();

    int count_mana();
    int count_attack();
    int count_spell_power();
    int count_health();
    int count_armor();
    int count_resist();


    //friends
    friend std::ostream &operator << (std::ostream &stream, const champion &out);

} champ;


#endif // _CHAMPION_H
