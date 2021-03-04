#include <iostream>

#include "ui/window.hpp"
#include "world/map_manager.hpp"
#include "world/ecs/entity.hpp"
#include "world/tilemap/tilemap.hpp"
int main(){



    auto window = ui::window::default_window();
    auto player = ecs::entity::create_default_player();

    world::tile::tilemap tm = world::tile::tilemap::load_from_file("src/assets/tiles.tmx");

    world::map_manager m;

    sf::Clock clock;


    auto e = ecs::entity::create_default_test_npc();
    m.add_entity(*e);
    m.add_entity(*player);

    while(window->isOpen()){


        window->clear_window();

        tm.draw(*window);

        m.inject_tilemap(tm);
        
        sf::Time elapsed = clock.restart();
        
        for(ecs::entity * entity : m.get_entities()){
            entity->update(m, *window, elapsed.asSeconds());
        }
        
        clock.restart();

        window->draw_sprites();
        window->display();

    }

    return 0;

}