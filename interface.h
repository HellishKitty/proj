#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <vector>
#include "champion/champion.h"


class interface {

private:

    static interface init();
    static std::vector<std::shared_ptr<champion>> init_champs();
    static std::vector<std::shared_ptr<item>> init_shop();
    static std::vector<std::shared_ptr<item>> init_stash();

    std::vector<std::shared_ptr<item>> stash;
    std::vector<std::shared_ptr<item>> shop;

    std::vector<std::shared_ptr<champion>> active_champs;
    std::shared_ptr<champion> current_champion;

    //
    interface(std::vector<std::shared_ptr<champion>> champs,
              std::vector<std::shared_ptr<item>> stash, std::vector<std::shared_ptr<item>> shop);
    interface() = default;



public:

    ~interface() = default;
    static interface start_interface();

    // options
    int main_menu();
    void print_stash();
    void print_shop();

    void buy_item();
    void buy(std::shared_ptr<item> i_to_buy);
    std::shared_ptr<item> search(const std::string &name);
    std::shared_ptr<item> search(const int &n);

    void _switch();
    void unequipp();
    void print_champs();
    void gearing();
    void select_champion();
    void create_champion();

};

#endif // _INTERFACE_H
