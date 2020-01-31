#include "component_graphics.hpp"


namespace ecs{


        
        void component_graphics::update(entity &entity, ui::window &window, float delta){

            m_animation.update(m_sprite, delta);
            window.draw(m_sprite);

        }

}