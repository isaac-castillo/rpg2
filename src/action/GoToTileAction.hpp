#ifndef __move_action__
#define __move_action__

#include "BaseAction.hpp"
#include "world/ecs/entity.hpp"
#include <SFML/System/Vector2.hpp>
namespace action {

using TileIndex = int;
class GoToTileAction : public PhysicsAction
{

private:

    TileIndex tileIndex;

public:

  GoToTileAction(TileIndex index);
  void execute(ecs::component_physics & physics, world::map_manager &, Second delta) override;
};

}// namespace Action

#endif