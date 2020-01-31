#include <catch2/catch.hpp>

#include "world/tilemap.hpp"
#include "ui/window.hpp"
namespace world {


TEST_CASE("test tilemap creation at center of screen")
{

    auto w = ui::window::default_window();
    //create a 12 x 10 tilemap
    tilemap t();


}


}