#ifndef __tile__
#define __tile__
#include <unordered_map>

#include "ui/window.hpp"
#include "Layer.hpp"
#include "RenderLayer.hpp"

#include <utility>

namespace world::tile {

    class Tile : public ui::Drawable {
    
        using RenderLayers = std::unordered_map<LayerType, RenderLayer>;
        private:
            RenderLayers renderLayers;
            Layer collisionLayer;

        public:
            void add_layer(LayerType layerType, const RenderLayer &);
            void delete_layer(LayerType);
            void draw(ui::window &) override;
            Layer& get_collision_layer();
            bool has_collision() const;


        };

}
#endif