#ifndef __entity__
#define __entity__

#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <memory>
#include <nlohmann/json.hpp>
#include "ui/window.hpp"

#include "component.hpp"
#include "component_input.hpp"
#include "component_graphics.hpp"
#include "component_physics.hpp"
#include "util/moving.hpp"
#include "util/direction.hpp"

#include "world/tilemap/Tile.hpp"

namespace ecs {

    class component_input;
    class component_graphics;
    class component_physics;
    class entity {
        
        private:
            const int m_id;
            std::vector<component> m_components;

            std::unique_ptr<component_input> m_input;
            std::unique_ptr<component_graphics> m_graphics;
            std::unique_ptr<component_physics> m_physics;

            util::direction m_direction;
            util::moving m_moving;

        public:
        
            entity();

            void update(world::map_manager &map_manager, ui::window &window, float delta);
            static std::unique_ptr<entity> create_default_player();
            static std::unique_ptr<entity> create_default_test_npc();
            static std::unique_ptr<entity> create_from_json(const std::string & filename);
            void set_input(std::unique_ptr<component_input> &input);
            void set_physics(std::unique_ptr<component_physics> &physics);
            void set_graphics(std::unique_ptr<component_graphics> &graphics);
            void set_direction(util::direction direction);
            void set_moving(util::moving moving);

            sf::Vector2f position();

            util::direction get_direction();
            util::moving get_moving();
        };


}


#endif

