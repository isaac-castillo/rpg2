#include <catch2/catch.hpp>

#include "action/GoToTileAction.hpp"
#include "world/map_manager.hpp"
#include "world/tilemap/Tilemap.hpp"
TEST_CASE("test GoToTileAction")
{


    /* Empty map_manager */

    world::map_manager mm({5,5,2,2});
    
    ecs::component_physics physics(2);
    
    action::GoToTileAction goToTile(0);
    goToTile.execute(physics, mm, 0);
    REQUIRE ( physics.get_position() == sf::Vector2f({0,0}) ); 

}
