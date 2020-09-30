#ifndef __layer_state__
#define __layer_state__

#include "layer_state.hpp"
#include "layer.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
namespace world {


    class layer_state : public sf::Drawable {


        private:

            bool m_collision;
            sf::Sprite m_sprite;

        public:
            layer_state();
            layer_state(sf::Sprite &sprite, bool collision);
            bool is_collision();
            void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    };
}
#endif