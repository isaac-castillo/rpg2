#include <iostream>

#include "ui/window.hpp"
#include "world/map_manager.hpp"
int main(){



    auto window = ui::window::default_window();

    world::map_manager m;
    m.load_tilemap("filename");
    while(window->isOpen()){
        window->clear();




        window->display();
    }

    return 0;

}