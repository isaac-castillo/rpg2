#include "Tile.hpp"
#include <utility>

namespace world::tile {

  void Tile::add_layer(LayerType a_layer, const RenderLayer &layer)
  {

    std::pair<LayerType, RenderLayer> pair(a_layer, layer);

    renderLayers.emplace(pair);
  }

  void Tile::draw(ui::window &window)
  {

    /* Naive drawing strategy */
    for (auto &pair : renderLayers) {
      pair.second.draw(window);
    }
  }

  bool Tile::has_collision() const
  {

    if (collisionLayer.is_collision()) {
      return true;
    }
    for (auto &pair : renderLayers) {
      if (pair.second.is_collision()) {
        return true;
      }
    }

    return false;
  }

  Layer &Tile::get_collision_layer()
  {

    return collisionLayer;
  }
}// namespace world::tile
