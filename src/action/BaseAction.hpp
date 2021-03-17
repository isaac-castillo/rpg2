#ifndef __action__
#define __action__

#include "world/map_manager.hpp"
#include "util/update.hpp"
#include "world/ecs/component_physics.hpp"
namespace action {

class PhysicsAction {

    public:
    virtual void execute(ecs::component_physics &physics, world::map_manager &, Second delta) = 0;
};


class BaseAction
{

public:

  virtual void execute(world::map_manager &, Second delta) = 0;
  

};

}// namespace Action

#endif