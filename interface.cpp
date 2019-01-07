#include <iostream>
#include <algorithm>
#include "interface.h"
#include "stuff"


int interface::main_menu() {

    int i = -1;

    while (true) {

        std::cout << "champion selected: " << this->current_champion->get_name() << std::endl;
        std::cout << "1) print stash" << std::endl;
        std::cout << "2) print shop" << std::endl;
        std::cout << "3) buy item" << std::endl;
        std::cout << "4) switch or equip item" << std::endl;
        std::cout << "5) unequip item" << std::endl;
        std::cout << "6) print selected champion info" << std::endl;
        std::cout << "7) print champions" << std::endl;
        std::cout << "8) gear up smth" << std::endl;
        std::cout << "9) switch champion" << std::endl;
        std::cout << "10) create a new champion" << std::endl;
        std::cout << "0) exit" << std::endl;
        slv::input("Input>", i);

        switch (i) {

            case 1:
                this->print_stash();
                break;

            case 2:
                this->print_shop();
                break;

            case 3:
                this->buy_item();
                break;

            case 4:
                this->_switch();
                break;

            case 5:
                this->unequipp();
                break;

            case 6:
                std::cout << *this->current_champion << "\n-------------------------\n";
                break;

            case 7:
                this->print_champs();
                break;

            case 8:
                this->gearing();
                break;

            case 9:
                this->select_champion();
                break;

            case 10:
                this->create_champion();
                break;

            case 0:
                return EXIT_SUCCESS;

            default:
                std::cout << "no such an option!" << std::endl;
                break;

        }

    }

}


void interface::print_champs() {

    std::cout << "your champions: " << std::endl;

    for (int i = 0; i != this->active_champs.size(); i++)
        std::cout << i + 1 << ". "<<  this->active_champs[i]->get_name() << std::endl;

    std::cout << "-------------------------" << std::endl;
}


void interface::print_stash() {

    std::cout << "----------stash----------\n-------------------------" << std::endl;

    for (short i = 0; i != this->stash.size(); i++) {

        this->stash[i]->print();
        std::cout << "-------------------------" << std::endl;

    }

    std::cout << "-------------------------" << std::endl;

}


void interface::print_shop() {

    std::cout << "----------shop-----------\n-------------------------" << std::endl;

    for (short i = 0; i != this->shop.size(); i++) {

        this->shop[i]->print();
        std::cout << "-------------------------" << std::endl;

    }

    std::cout << "-------------------------" << std::endl;

}


void interface::buy_item() {

    int i = -1, n = 0;
    std::string name;
    while (true) {
        slv::input("1) Search by number || 2) Search by name || 0) Go back\nInput>", i);

        switch (i) {

            case 1:
                slv::input("enter number: ", n);
                this->buy(this->search(n));
                break;

            case 2:
                slv::input("enter name: ", name);
                this->buy(this->search(name));
                break;

            case 0:
                return;

            default:
                std::cout << "there is no such an option!" << std::endl;
                break;

        }

    }

}


void interface::buy(std::shared_ptr<item> i_to_buy) {

    if (i_to_buy == nullptr)
        std::cout << "there is no such an item" << std::endl;
    else {

        this->shop.erase(std::remove(this->shop.begin(), this->shop.end(), i_to_buy), this->shop.end());
        this->stash.push_back(i_to_buy);

        std::cout << "item bought! check out the stash!" << std::endl;
    }

}


std::shared_ptr<item> interface::search(const std::string &name) {

    std::shared_ptr<item> result = nullptr;

    for (int i = 0; i != this->shop.size(); i++) {

        if (this->shop[i]->get_name() == name) {
            result = shop[i];
            break;
        }

    }

    return result;
}


std::shared_ptr<item> interface::search(const int &n) {

    std::shared_ptr<item> result = nullptr;

    if (n < 0 or n >= this->shop.size())
        std::cout << "invalid value" << std::endl;
    else
        result = this->shop[n];

    return result;
}


// костыль
void interface::_switch() {

    int i = -1;
    std::shared_ptr<item> tmp;

    while (true) {

        slv::input("enter n of item or -1 to go back\nInput>", i);

        if (i == -1)
            return;

        if (i < -1 or i >= this->stash.size()) {
            std::cout << "there is no such an item!" << std::endl;
            continue;
        }

        switch (item_type_map[this->shop[i]->get_type()]) {

            case 1:
                tmp = this->current_champion->unequip_arm();
                if (tmp) this->stash.push_back(tmp);
                this->current_champion->equip_arm(this->stash[i]->convert_arm());
                this->stash.erase(this->stash.begin() + i);
                break;

            case 2:
                tmp = this->current_champion->unequip_outfit();
                if (tmp) this->stash.push_back(tmp);
                this->current_champion->equip_outfit(this->stash[i]->convert_outfit());
                this->stash.erase(this->stash.begin() + i);
                break;

            case 3:
                tmp = this->current_champion->unequip_belt();
                if (tmp) this->stash.push_back(tmp);
                this->current_champion->equip_belt(this->stash[i]->convert_belt());
                this->stash.erase(this->stash.begin() + i);
                break;

            case 4:
                tmp = this->current_champion->unequip_bracelet();
                if (tmp) this->stash.push_back(tmp);
                this->current_champion->equip_bracelet(this->stash[i]->convert_bracelet());
                this->stash.erase(this->stash.begin() + i);
                break;

            case 5:
                tmp = this->current_champion->unequip_necklace();
                if (tmp) this->stash.push_back(tmp);
                this->current_champion->equip_necklace(this->stash[i]->convert_necklace());
                this->stash.erase(this->stash.begin() + i);
                break;

            case 6:
                tmp = this->current_champion->unquip_plume();
                if (tmp) this->stash.push_back(tmp);
                this->current_champion->equip_plume(this->stash[i]->convert_plume());
                this->stash.erase(this->stash.begin() + i);
                break;

            default:
                break;


        }

    }

}


void interface::unequipp() {

    int i = 0;
    std::shared_ptr<item> tmp;

    while (true) {

        std::cout << "Unequipp items: " << std::endl;
        std::cout << "1) Arm\n2) Outfit\n3) Belt" << std::endl;
        std::cout << "4) Bracelet\n5) Necklace\n6) Plume" << std::endl;
        std::cout << "0) Go back" << std::endl;
        slv::input("Input>", i);

        switch (i) {

            case 1:
                tmp = this->current_champion->unequip_arm();
                if (tmp) this->stash.push_back(tmp);
                break;

            case 2:
                tmp = this->current_champion->unequip_outfit();
                if (tmp) this->stash.push_back(tmp);
                break;

            case 3:
                tmp = this->current_champion->unequip_belt();
                if (tmp) this->stash.push_back(tmp);
                break;

            case 4:
                tmp = this->current_champion->unequip_bracelet();
                if (tmp) this->stash.push_back(tmp);
                break;

            case 5:
                tmp = this->current_champion->unequip_necklace();
                if (tmp) this->stash.push_back(tmp);
                break;

            case 6:
                tmp = this->current_champion->unquip_plume();
                if (tmp) this->stash.push_back(tmp);
                break;

            case 0:
                return;

            default:
                std::cout << "there is no such an option!" << std::endl;
                break;

        }

    }

}


void interface::gearing() {

    int i = 0;

    while (true) {

        std::cout << "Gear up items: " << std::endl;
        std::cout << "1) Arm\n2) Outfit\n3) Belt" << std::endl;
        std::cout << "4) Bracelet\n5) Necklace\n6) Plume" << std::endl;
        std::cout << "0) Go back" << std::endl;

        slv::input("Input>", i);

        switch (i) {

            case 1:
                this->current_champion->gear_up_arm();
                break;

            case 2:
                this->current_champion->gear_up_outfit();
                break;

            case 3:
                this->current_champion->gear_up_belt();
                break;

            case 4:
                this->current_champion->gear_up_bracelet();
                break;

            case 5:
                this->current_champion->gear_up_necklace();
                break;

            case 6:
                this->current_champion->gear_up_plume();
                break;

            case 0:
                return;

            default:
                std::cout << "there is no such an option!" << std::endl;
                break;

        }

    }

}


void interface::select_champion() {

    int i = 0;
    std::string name;

    slv::input("enter name: ", name);

    for (i = 0; i != this->active_champs.size(); i++) {

        if (this->active_champs[i]->get_name() == name) {

            this->current_champion = this->active_champs[i];
            std::cout << "new champion selected" << std::endl;
            break;

        }

    }

    if (i == this->active_champs.size())
        std::cout << "there is no such a champion" << std::endl;
}


void interface::create_champion() {

    std::string name;
    slv::input("enter name: ", name);
    this->active_champs.emplace_back(std::make_shared<champion>(name));
    std::cout << "champion created!" << std::endl;
}


interface::interface(std::vector<std::shared_ptr<champion>> champs, std::vector<std::shared_ptr<item>> stash,
                     std::vector<std::shared_ptr<item>> shop) {

    this->active_champs = champs;
    this->stash = stash;
    this->shop = shop;

}


interface interface::start_interface() {

    int i = -1;

    while (true) {
        slv::input("Init defaults?\n1) Yes || 2) No\nInput>", i);

        switch (i) {

            case 1:
                return init();

            case 2:
                return interface();

            default:
                std::cout << "no such an option" << std::endl;
                break;
        }

    }

}


// inits
interface interface::init() {

    std::vector<std::shared_ptr<item>> shop = interface::init_shop();
    std::vector<std::shared_ptr<item>> stash = interface::init_stash();
    std::vector<std::shared_ptr<champion>> champs = interface::init_champs();

    auto _interface_ = interface(champs, stash, shop);
    _interface_.current_champion = champs[0];

    return _interface_;
}


std::vector<std::shared_ptr<item>> interface::init_stash() {

    std::vector<std::shared_ptr<item>> stash;

    stash.emplace_back(std::make_shared<steel_arm>("training sword", 1, 0, 1, 70, 100, 0));
    stash.emplace_back(std::make_shared<outfit>("training plate", 1, 0, 50, 50, 400, 100, 100));

    return stash;
}


std::vector<std::shared_ptr<item>> interface::init_shop() {

    std::vector<std::shared_ptr<item>> shop;

    shop.emplace_back(std::make_shared<magic_arm>("training orb", 1, 0, 20, 300, 100, 0));
    shop.emplace_back(std::make_shared<magic_arm>("grimoire", 2, 0, 5, 500, 250, 0.05));
    shop.emplace_back(std::make_shared<magic_arm>("dragon orb", 3, 0, 20, 700, 400, 0.1));

    shop.emplace_back(std::make_shared<steel_arm>("training sword", 1, 0, 2, 150, 100, 0));
    shop.emplace_back(std::make_shared<steel_arm>("battle axe", 2, 0, 2, 400, 150, 0));
    shop.emplace_back(std::make_shared<steel_arm>("divine spear", 3, 0, 5, 400, 300, 0.1));

    shop.emplace_back(std::make_shared<devine_arm>("ancient staff", 3, 0, 5, 300, 200, 0.1, 600, 300, 0.1));

    shop.emplace_back(std::make_shared<outfit>("training plate", 1, 0, 50, 50, 400, 100, 100));
    shop.emplace_back(std::make_shared<outfit>("chain mail", 2, 0, 150, 150, 1000, 200, 200));
    shop.emplace_back(std::make_shared<outfit>("daeva armor", 3, 0, 300, 300, 2000, 400, 400));

    shop.emplace_back(std::make_shared<plume>("daeva plume", 3, 0, 1000, 100, 100));
    shop.emplace_back(std::make_shared<necklace>("dragon necklace", 3, 0, 0.1, 300));
    shop.emplace_back(std::make_shared<bracelet>("divine bracelet", 3, 0, 0.1, 400));
    shop.emplace_back(std::make_shared<belt>("victorious belt", 3, 0, 100, 100));

    return shop;
}


std::vector<std::shared_ptr<champion>> interface::init_champs() {

    stats _stats {};
    _stats.set_defaults();
    std::vector<std::shared_ptr<champion>> _champs_;

    std::shared_ptr<arm> _arm = std::make_shared<devine_arm>("Rebellion", 3, 0, 3, 400, 300, 0.1, 500, 300, 0.1);
    std::shared_ptr<outfit> _outfit = std::make_shared<outfit>("Red Queen", 3, 0, 300, 300, 3000, 400, 400);
    std::shared_ptr<belt> _belt = std::make_shared<belt>("Devil Trigger", 3, 0, 200, 200);
    std::shared_ptr<bracelet> _bracelet = std::make_shared<bracelet>("Blue Rose", 3, 0, 0.1, 500);
    std::shared_ptr<necklace> _necklace = std::make_shared<necklace>("Spiral", 3, 0, 0.1, 400);
    std::shared_ptr<plume> _plume = std::make_shared<plume>("Red Rose", 3, 0, 2000, 150, 150);

    _champs_.emplace_back(std::make_shared<champion>("Dante", _stats, _arm, _outfit, _belt, _bracelet, _necklace, _plume));
    _champs_[0]->_stats.mana += _champs_[0]->count_mana();
    _champs_[0]->_stats.attack_range += _arm->get_attack_range();
    _champs_[0]->_stats.attack += _champs_[0]->count_attack();
    _champs_[0]->_stats.accuracy += _arm->get_accuracy();
    _champs_[0]->_stats.attack_speed += _arm->get_attack_speed_bonus();
    _champs_[0]->_stats.spell_power += _champs_[0]->count_spell_power();
    _champs_[0]->_stats.spell_accuracy += _arm->get_spell_accuracy();
    _champs_[0]->_stats.cast_speed += _arm->get_cast_speed_bonus();
    _champs_[0]->_stats.health += _champs_[0]->count_health();
    _champs_[0]->_stats.armor += _champs_[0]->count_armor();
    _champs_[0]->_stats.resist += _champs_[0]->count_resist();
    _champs_[0]->_stats.evasion += _outfit->get_evasion();
    _champs_[0]->_stats.dispelling += _outfit->get_dispelling();

    return _champs_;
}
