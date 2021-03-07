#include "map_manager.hpp"

namespace world {

    map_manager::map_manager(){

    }

    std::vector<ecs::entity *> map_manager::get_entities(){
        return entities;
    }
    
    void map_manager::add_entity(ecs::entity &entity){
        entities.push_back(&entity);

    }

    bool map_manager::is_collision_tile(const sf::Vector2f &point) const{


        auto tile = t->pointToTile(point);
        return tile.has_collision();
    }
    void map_manager::inject_tilemap(world::tile::Tilemap & tm){
        t = &tm;
    }
}