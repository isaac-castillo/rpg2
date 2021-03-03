#include <catch2/catch.hpp>

#include "world/tilemap/tile.hpp"

namespace world {


TEST_CASE("modify collision layer to have collision"){


    tile::Tile t;

    t.get_collision_layer().set_collision(tile::Collision::True);
    REQUIRE( t.has_collision() );

}

TEST_CASE("remove collision layer's collision property")
{

    tile::Tile t;

    t.get_collision_layer().set_collision(tile::Collision::False);
    REQUIRE ( !t.has_collision() );

}

TEST_CASE("remove collision layer's collision property but not the other layers")
{

    tile::Tile t;

    t.get_collision_layer().set_collision(tile::Collision::False);

    t.add_layer(tile::LayerType::ground_layer, tile::RenderLayer(tile::Collision::True));

    REQUIRE(t.has_collision());
}


}