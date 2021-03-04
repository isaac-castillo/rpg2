#include "component_animation.hpp"
namespace ecs {

    component_animation::component_animation(const std::vector<sf::IntRect> & frames, const std::vector<float>  &time_in_frames) : m_frames(frames), m_time_in_frames(time_in_frames){

    }

    void component_animation::update(sf::Sprite &sprite, float delta)
    {
        m_time_elapsed += delta;

        if( m_time_elapsed >= m_time_in_frames[m_current_frame_index]){
            m_time_elapsed = 0;
            m_current_frame_index++;

            if(m_current_frame_index >= m_frames.size()){
                m_current_frame_index = 0;
            }
        
        }

        set_frame(sprite, m_current_frame_index);

    }

    void component_animation::set_frame(sf::Sprite &sprite, int frame){
        sprite.setTexture(m_texture);
        sprite.setTextureRect(m_frames[frame]);
    }

    void component_animation::receive(){
        
    }

    void component_animation::set_texture_file(std::string filename) {

        m_texture.loadFromFile(filename);
    }
    
}