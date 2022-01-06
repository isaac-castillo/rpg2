#ifndef __base_tile__
#define __base_tile__
#include <unordered_map>

#include "Layer.hpp"

#include <utility>

namespace world::tile {

  class BaseTile {

  private:
    Layer collisionLayer;

  public:
    Layer &get_collision_layer()
    {
      return collisionLayer;
    }
    bool has_collision() const
    {
      if (collisionLayer.is_collision()) {
        return true;
      }

      return false;
    }
  };

}// namespace world::tile
#endif