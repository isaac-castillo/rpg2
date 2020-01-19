#ifndef __entity__
#define __entity__

#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <memory>
#include <nlohmann/json.hpp>

#include "component.hpp"
#include "component_input.hpp"
#include "component_graphics.hpp"
#include "component_physics.hpp"

namespace ecs {
class entity : public sf::Sprite {
        
    private:
        const int id;
        std::vector<component> m_components;

        std::shared_ptr<component_input> m_input;
        std::shared_ptr<component_graphics> m_graphics;
        std::shared_ptr<component_physics> m_physics;

    public:
    
        static std::shared_ptr<entity> create_from_json(std::string filename);
        void set_input(component_input &input);
        void set_physics(component_physics &physics);
        void set_graphics(component_graphics &graphics);
    };
}


#endif

