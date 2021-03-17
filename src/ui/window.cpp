#include "window.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <algorithm>
#include "util/global.hpp"
namespace ui
{



window::window() : RenderWindow(sf::VideoMode(WIDTH, HEIGHT), global::GAMENAME){

};

window window::default_window()
{
    return window();
}

void window::clear_window()
{
    clear();
    m_drawables.clear();
}

void window::add_sprite(sf::Sprite &sprite)
{
    m_drawables.push_back(sprite);
}

void window::draw_sprites()
{

    std::sort(m_drawables.begin(), m_drawables.end(), [](sf::Sprite one, sf::Sprite two) {
        auto pos1 = one.getPosition().y;
        auto pos2 = two.getPosition().y;
        return pos1 < pos2;
    });

    for (sf::Sprite &sprite : m_drawables)
    {
        draw(sprite);
    }
}

} // namespace ui