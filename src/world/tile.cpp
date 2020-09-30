#include "tile.hpp"
#include <utility>

namespace world {
    void tile::add_to_layer(layer a_layer, layer_state state){



        std::pair<layer, layer_state> pair(a_layer, state);
        
         m_layers.emplace(pair);

    }

    void tile::draw(ui::window &window){


        auto thing = m_layers.find(layer::ground_layer);
        window.draw(thing->second);


    }
}