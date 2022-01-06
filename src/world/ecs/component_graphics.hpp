#ifndef __component_graphics__
#define __component_graphics__
#include <algorithm>

#include <SFML/Graphics/Sprite.hpp>

#include "component.hpp"
#include "component_animation.hpp"
#include "entity.hpp"
#include "ui/window.hpp"
#include "unordered_map"
#include "util/direction.hpp"
#include "util/update.hpp"
#include "world/map_manager.hpp"
#include <utility>

namespace ecs {

  class entity;
  class component_graphics : public component {

  private:
    std::unordered_map<util::direction, std::unique_ptr<component_animation>> m_direction_animations;
    sf::Sprite m_sprite;
    std::unique_ptr<component_animation> m_idle_animation;

  public:
    component_graphics();
    void add_direction_animation(util::direction direction, std::unique_ptr<component_animation> &animation);
    void update(entity &entity, ui::window &window, Second delta);
    void receive() override;
  };

}// namespace ecs
#endif