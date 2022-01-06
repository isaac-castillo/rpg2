#include <iostream>

#include "ui/window.hpp"
#include "world/ecs/entity.hpp"
#include "world/map_manager.hpp"
#include "world/tilemap/Tilemap.hpp"
// #include "action/MoveAction.hpp"
#include "world/tilemap/Tile.hpp"

int main()
{

  ui::window window = ui::window::default_window();
  auto player = ecs::entity::create_default_player();
  auto e = ecs::entity::create_default_test_npc();

  world::tile::Tilemap tilemap = world::tile::Tilemap::load_from_file("src/assets/tiles.tmx");
  sf::Clock clock;

  // Action::MoveAction action;

  world::Entities entities{ e.get(), player.get() };
  world::map_manager mm(tilemap, entities);

  /* Old API, Unused */
  // m.add_entity(*e);
  // m.add_entity(*player);
  // mm.inject_tilemap(tilemap);

  while (window.isOpen()) {

    window.clear_window();
    tilemap.draw(window);

    sf::Time elapsed = clock.restart();

    for (ecs::entity *entity : mm.get_entities()) {
      entity->update(mm, window, elapsed.asSeconds());
    }

    window.draw_sprites();
    window.display();
    clock.restart();
  }

  return 0;
}