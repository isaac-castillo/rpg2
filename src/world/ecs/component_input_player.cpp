#include "component_input_player.hpp"

namespace ecs {

  void component_input_player::update(entity &entity, float delta)
  {

    if (entity.get_moving() == util::moving::MOVING) {
      return;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      entity.set_direction(util::direction::LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      entity.set_direction(util::direction::RIGHT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      entity.set_direction(util::direction::UP);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      entity.set_direction(util::direction::DOWN);
    } else {

      return;
    }

    entity.set_moving(util::moving::STARTED);
  }

  void component_input_player::receive()
  {
  }
}// namespace ecs