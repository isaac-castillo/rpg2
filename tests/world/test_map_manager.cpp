#include <catch2/catch.hpp>

#include "world/map_manager.hpp"
#include "world/tilemap/BaseTile.hpp"
#include "world/tilemap/BaseTilemap.hpp"
#include "world/ecs/entity.hpp"
#include <vector>

namespace world {


using MapManager = world::map_manager;

TEST_CASE("map_manager constructors")
{


  world::tile::Tilemap t = world::tile::Tilemap::load_from_file("test.tmx");

  Entities entities;

  MapManager mm(t, entities);
  REQUIRE( mm.is_collision_tile({ 0,0 }));


  MapManager mm2(world::tile::BaseTilemap(5,5,2,2));

}


}// namespace world