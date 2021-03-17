#include <catch2/catch.hpp>

#include "ui/window.hpp"
#include "world/ecs/entity.hpp"
#include "world/ecs/component_physics.hpp"
#include "world/map_manager.hpp"

using namespace ecs;

TEST_CASE("entity default creation from json")
{
    auto entity = entity::create_default_player();


}
