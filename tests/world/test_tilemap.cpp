#include <catch2/catch.hpp>

#include "world/tilemap/Tilemap.hpp"

namespace world::tile {

  TEST_CASE("load from tilemap file")
  {

    world::tile::Tilemap t = world::tile::Tilemap::load_from_file("test.tmx");
  }

  TEST_CASE("BaseTilemap constructor")
  {

    BaseTilemap tm(5, 3, 10, 8);

    REQUIRE(tm.column_count() == 5);
    REQUIRE(tm.row_count() == 3);

    REQUIRE(tm.tile_height() == 10);
    REQUIRE(tm.tile_height() == 8);
  }

  TEST_CASE("point to tile")
  {

    BaseTilemap tm2(10, 10, 10, 10);
    auto idx = tm2.pointToIndex({ 0, 0 });

    REQUIRE(idx == 0);
  }

}// namespace world::tile