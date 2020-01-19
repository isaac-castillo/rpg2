#ifndef __component_graphics__
#define __component_graphics__
#include <algorithm>

#include "entity.hpp"
#include "component.hpp"
#include "../map_manager.hpp"


namespace ecs{
    
    class entity;
    class component_graphics : public component
    {

        public:

            void update(entity &entity, world::map_manager &map_manager, float delta);


    };


}
#endif