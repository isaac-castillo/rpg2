#ifndef __action__
#define __action__

#include "util/update.hpp"
#include "world/ecs/component_physics.hpp"
#include "world/map_manager.hpp"
namespace action {

  class PhysicsAction {

  public:
    virtual void execute(ecs::component_physics &physics, world::map_manager &, Second delta) = 0;
  };

  class BaseAction {

  public:
    virtual void execute(world::map_manager &, Second delta) = 0;
  };

}// namespace action

#endif