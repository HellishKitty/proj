#include <iostream>
#include <memory>
#include "stuff"
#include "champion/champion.h"
#include "interface.h"


int main() {

    std::cout << "starting interface..." << std::endl;
    auto _interface_ = interface::start_interface();
    _interface_.main_menu();

    return EXIT_SUCCESS;
}