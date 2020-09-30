#include "map_manager.hpp"

namespace world {

    // void map_manager::load_tilemap(std::string filename){
        
    // }

    std::vector<ecs::entity *> map_manager::get_entities(){
        return entities;
    }
    
    std::vector<ecs::entity> map_manager::add_entity(ecs::entity &entity){
        entities.push_back(&entity);
    }
}