#ifndef __component_physics__
#define __component_physics__
#include "component.hpp"
#include "entity.hpp"
#include "world/map_manager.hpp"
#include "util/rectangle.hpp"
#include "util/tile_tween.hpp"
#include "world/tilemap/Tile.hpp"
#include <memory>
namespace ecs { 
    class component_physics : public component
    {
    private:
        sf::Vector2f m_velocity;
        sf::Vector2f m_position;
        util::rectangle m_bounding_box;
        float m_speed = 16.0;

    private:

        float m_tile_width;

        std::unique_ptr<tile_tween> tile_transfer;


    public:
        explicit component_physics(float tile_width);

        virtual void update(entity &entity, world::map_manager &map_manager, float delta);
        bool collides_with(sf::Vector2f &pos, entity &e2);


        entity *collides_with_any(ecs::entity &self, sf::Vector2f &pos, world::map_manager &map_manager);

        void receive() override;
        sf::Vector2f get_position();
        util::rectangle& get_bounding_box();
        void set_position(const sf::Vector2f & pos);


    };

}
#endif