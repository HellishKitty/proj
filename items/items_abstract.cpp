#include <iostream>
#include "items_abstract.h"


item::~item() {

    std::cout << this->name << " destroyed" << std::endl;

}


std::map <int, std::string>rank_map = {

        { 1, "common"},
        { 2, "heroic"},
        { 3, "legendary"},

};


std::map <std::string, int> item_type_map = {

        { "steel arm", 1 },
        { "magic arm", 1 },
        { "divine arm", 1 },
        { "outfit", 2 },
        { "belt", 3 },
        { "bracelet", 4 },
        { "necklace", 5 },
        { "plume", 6 }

};
