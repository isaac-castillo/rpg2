#include "component_physics.hpp"

#include "world/map_manager.hpp"
#include <iostream>
namespace ecs {

  component_physics::component_physics(float tile_width) : m_tile_width(tile_width) {}

  void component_physics::update(entity &entity, world::map_manager &map_manager, float delta)
  {

    if (entity.get_moving() == util::moving::STARTED) {
      auto current_position = entity.position();
      auto new_position = current_position;
      switch (entity.get_direction()) {

        case util::direction::DOWN:
          new_position = sf::Vector2f(current_position.x, current_position.y + m_tile_width);
          break;
        case util::direction::LEFT:
          new_position = sf::Vector2f(current_position.x - +m_tile_width, current_position.y);
          break;
        case util::direction::RIGHT:
          new_position = sf::Vector2f(current_position.x + m_tile_width, current_position.y);
          break;
        case util::direction::UP:
          new_position = sf::Vector2f(current_position.x, current_position.y - m_tile_width);
          break;
        default:
          new_position = sf::Vector2f(current_position.x, current_position.y + m_tile_width);
      }

      tile_transfer = std::make_unique<tile_tween>(current_position, new_position, 0.5f);
      entity.set_moving(util::moving::MOVING);

      std::cout << new_position.x << " " << new_position.y << std::endl;
      // if (map_manager.is_collision_tile(new_position) || collides_with_any(entity, new_position, map_manager))
      // {
      //     entity.set_moving(util::moving::NOT_MOVING);
      // }
    }

    if (entity.get_moving() == util::moving::MOVING) {

      m_position = tile_transfer->update(delta);

      if (tile_transfer->finished()) {
        entity.set_moving(util::moving::NOT_MOVING);
      }

    } else {
      m_velocity = sf::Vector2f(0, 0);
    }
  }

  bool component_physics::collides_with(sf::Vector2f &pos, entity &e2)
  {
    return pos.x == e2.position().x && pos.y == e2.position().y;
  }

  entity *component_physics::collides_with_any(ecs::entity &self, sf::Vector2f &pos, world::map_manager &map_manager)
  {

    for (ecs::entity *entity : map_manager.get_entities()) {

      if (collides_with(pos, *entity) && &self != entity) {
        return entity;
      }
    }
    return nullptr;
  }

  util::rectangle &component_physics::get_bounding_box()
  {

    // return util::rectangle();
  }

  void component_physics::receive()
  {
  }

  sf::Vector2f component_physics::get_position()
  {
    return m_position;
  }

  void component_physics::set_position(const sf::Vector2f &pos)
  {
    m_position = pos;
  }
}// namespace ecs