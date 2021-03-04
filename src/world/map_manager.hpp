#ifndef __map_manager__
#define __map_manager__

#include <string>
#include <unordered_map> 
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "tilemap/tilemap.hpp"
namespace ecs
{
    class entity;
}
namespace world {

    class map_manager {

        private:
            std::vector<ecs::entity *> entities;
            world::tile::tilemap * t = nullptr;   

        public:
            map_manager();
            std::vector<ecs::entity *> get_entities();
            void add_entity(ecs::entity & entity);

            bool is_collision_tile(const sf::Vector2f & point) const;
            void inject_tilemap(world::tile::tilemap &);

    };

}
#endif
