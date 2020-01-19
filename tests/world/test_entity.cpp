#include <catch2/catch.hpp>

#include "world/ecs/entity.hpp"

using namespace ecs;

TEST_CASE("entity default creation from json")
{

    auto e = entity::create_from_json("entity_test.json");

}
