#include "component_graphics.hpp"


namespace ecs {


        component_graphics::component_graphics() : m_sprite(sf::Sprite()) {

        }
        
        void component_graphics::update(entity &entity, ui::window &window, Second delta){



            if(entity.get_moving() == util::moving::MOVING){

                auto m_animation = m_direction_animations.find(entity.get_direction());
                if(m_animation != m_direction_animations.end()){

                    m_animation->second.get()->update(m_sprite, delta);
                }
            }

            if(entity.get_moving() == util::moving::NOT_MOVING || entity.get_moving() == util::moving::IMMOBILE){
                auto m_animation = m_direction_animations.find(entity.get_direction());
                if (m_animation != m_direction_animations.end())
                {

                    m_animation->second.get()->set_frame(m_sprite, 0);
                }
            }

            m_sprite.setPosition(entity.position());
            window.add_sprite(m_sprite);

        }

        void component_graphics::receive(){

        }

        void component_graphics::add_direction_animation(util::direction direction, std::unique_ptr<component_animation> &animation)
        {
            m_direction_animations[direction] = std::move(animation);
        }

}