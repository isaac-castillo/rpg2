#include "layer_state.hpp"

namespace world
{


    layer_state::layer_state(sf::Sprite &sprite, bool collision) : m_sprite(sprite), m_collision(collision){

    }


    layer_state::layer_state() {
        
    }

    bool layer_state::is_collision()
    {
        return m_collision;
    }

    void layer_state::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {

        //target.draw(layers[0].sprite, states);
        //cannot use lambda
        // sf::RectangleShape rectangle(sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height));
        // rectangle.setPosition(m_sprite.getPosition()+sf::Vector2f(1,1));
        // rectangle.setFillColor(sf::Color::Black);
        // target.draw(rectangle);
        
        target.draw(m_sprite, states);
    }

} // namespace world