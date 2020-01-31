#ifndef __component_graphics__
#define __component_graphics__
#include <algorithm>

#include <SFML/Graphics/Sprite.hpp>

#include "entity.hpp"
#include "component.hpp"
#include "world/map_manager.hpp"
#include "ui/window.hpp"
#include "component_animation.hpp"

namespace ecs {
    
    class entity;
    class component_graphics : public component
    {

        private:
            component_animation m_animation;
            sf::Sprite m_sprite;

        public:

            void set_animation(component_animation &animation);
            void update(entity &entity, ui::window &window, float delta);


    };


}
#endif