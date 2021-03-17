#ifndef map_manager__
#define map_manager__

#include <string>
#include <unordered_map>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "tilemap/Tilemap.hpp"
// #include "trigger/Trigger.hpp"
#include "tilemap/BaseTilemap.hpp"
namespace ecs {
class entity;
}
namespace world {


using Entities = std::vector<ecs::entity *>;
// using Triggers = const std::unordered_map<int, trigger::Trigger>;

class map_manager
{

private:
  tile::Tilemap *t;
  Entities entities;
  //   std::unordered_map<int, trigger::Trigger> triggers;

public:
  map_manager(const tile::BaseTilemap & tilemap) {


      auto tm = tile::Tilemap::create_base_tilemap(tilemap);
      t = &tm;
  }
  map_manager(tile::Tilemap &tilemap, const Entities &e = Entities()) : t(&tilemap), entities(e)
  {
  }

  Entities get_entities()
  {
    return entities;
  }

  void add_entity(ecs::entity &entity)
  {
    entities.push_back(&entity);
  }

  bool is_collision_tile(const sf::Vector2i &point) const
  {


    auto const tile = t->pointToTile(point);
    return tile.has_collision();
  }
  void inject_tilemap(tile::Tilemap &tm)
  {
    t = &tm;
  }

  //   void add_trigger_to_tile(trigger::Trigger &trigger, int row, int column)
  //   {

  //     int index = row * t->column_count() + column;

  //     triggers[index] = trigger;
  //   }
};

}// namespace world
#endif
