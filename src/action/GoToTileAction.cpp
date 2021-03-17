#include "GoToTileAction.hpp"

namespace action {


GoToTileAction::GoToTileAction(TileIndex index) : tileIndex(index) {

}

void GoToTileAction::execute(ecs::component_physics & physics, world::map_manager &, Second delta)
{

    physics.set_position({0,0});
    
}

}// namespace Action