#include <catch2/catch.hpp>

#include "ui/window.hpp"

using namespace ui;

TEST_CASE("window default creation"){


    auto w = window::default_window();

    auto size = w.getSize();
    REQUIRE(size.x == 600);
    REQUIRE(size.y == 400);

}






