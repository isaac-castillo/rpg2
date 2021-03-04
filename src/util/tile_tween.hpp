#include <tweeny/tweeny.h>
#include <SFML/System/Vector2.hpp>
#include <iostream>
class tile_tween {

    private: 
        float m_time_elapsed;
        float m_time_to_reset;
        sf::Vector2f m_start;
        sf::Vector2f m_end;
        tweeny::tween<float, float> m_tween;

    public: 


        tile_tween(sf::Vector2f start, sf::Vector2f end, float duration) : m_time_elapsed(0), m_time_to_reset(duration),
        m_start(start), m_end(end) {
            m_tween = tweeny::from(m_start.x, m_start.y).to(m_end.x, m_end.y).during(100).via(tweeny::easing::linear);
       
       }
        sf::Vector2f update(float delta){

            auto res = m_tween.step(delta * 4);
            m_time_elapsed += delta;
            if(finished()){
                return sf::Vector2f(m_end.x, m_end.y);
            }
            return sf::Vector2f(res.at(0), res.at(1));
        }

        bool finished(){
            return m_tween.progress() >= 0.98f;
        }

};