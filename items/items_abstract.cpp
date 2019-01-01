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
