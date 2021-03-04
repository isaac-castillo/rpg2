#ifndef __component_animation__
#define __component_animation__
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "component.hpp"


namespace ecs {

    class component_animation : component {

        private:
            sf::Texture m_texture;
            std::vector<sf::IntRect> m_frames;
            std::vector<float> m_time_in_frames;
            float m_time_elapsed = 0;
            int m_current_frame_index = 0;

        public:

            component_animation( const std::vector<sf::IntRect> & frames, const std::vector<float> &timeInFrame);
            void update(sf::Sprite &sprite, float delta);
            void receive() override;
            void set_texture_file(std::string filename);
            void set_frame(sf::Sprite &sprite, int frame);
    };

}
#endif