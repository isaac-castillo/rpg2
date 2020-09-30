#ifndef __tile__
#define __tile__
#include <unordered_map>
#include <SFML/Graphics/Sprite.hpp>
#include "world/layer.hpp"
#include "world/layer_state.hpp"
#include "world/ecs/entity.hpp"
#include "ui/window.hpp"
#include <utility>

namespace world {

    class tile {
    
        private:
            std::unordered_map<layer, layer_state> m_layers;
            std::unordered_map<layer, sf::IntRect> int_rect;

        public:
            void add_to_layer(layer layer, layer_state layer_state);
            void draw(ui::window &window);

        };

}
#endif