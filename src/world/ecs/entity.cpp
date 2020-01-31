#include "entity.hpp"

namespace ecs {
    
    std::shared_ptr<entity> entity::create_from_json(std::string filename){


    }

    void entity::update(world::map_manager &map_manager, ui::window &window, float delta){
        m_input->update(*this, delta);
        m_graphics->update(*this, window, delta);
        m_physics->update(*this, map_manager, delta);
    }

    std::shared_ptr<entity> entity::create_default_player(){

        
    }
    void entity::set_input(component_input &input){

    }
    void entity::set_physics(component_physics &physics){

    }

    void entity::set_graphics(component_graphics &graphics){

    }
}