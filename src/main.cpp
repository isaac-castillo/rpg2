#include <iostream>

#include "ui/window.hpp"

int main(){



    auto window = ui::window::default_window();
    while(window->isOpen()){
        window->clear();




        window->display();
    }

    return 0;

}