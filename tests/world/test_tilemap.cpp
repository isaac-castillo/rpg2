#include <catch2/catch.hpp>

#include "world/tilemap/Tilemap.hpp"


namespace world {


TEST_CASE("load from tilemap")
{

 
    world::tile::Tilemap t = world::tile::Tilemap::load_from_file("hi");


}


}