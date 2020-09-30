#ifndef __map_manager__
#define __map_manager__

#include <string>
#include <unordered_map> 
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace ecs
{
    class entity;
}
namespace world {

    class map_manager {

        private:
            std::vector<ecs::entity *> entities;
            std::unordered_map<ecs::entity *, sf::Vector2f> positions;

        public:
            std::vector<ecs::entity *> get_entities();
            // void load_tilemap(std::string filename);
            std::vector<ecs::entity> add_entity(ecs::entity & entity);

    };

}
#endif
