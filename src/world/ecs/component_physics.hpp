#ifndef __component_physics__
#define __component_physics__
#include "component.hpp"
#include "entity.hpp"
#include "world/map_manager.hpp"
#include "world/rectangle.hpp"

namespace ecs { 
    class component_physics : public component
    {

        int m_id;
        util::rectangle m_bounding_box;

    public:
        void update(world::map_manager &map_manager, float delta);
        bool collides_with(entity &e2);
        void collides__with_any(entity &e, world::map_manager &map_manager);

        util::rectangle& get_bounding_box();
    };

}
#endif