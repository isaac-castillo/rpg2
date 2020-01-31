#include "window.hpp"

namespace ui {

window::window() : RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "rpg2")
{
 
};

std::unique_ptr<window> window::default_window()
{

    return std::make_unique<window>();
    }



}