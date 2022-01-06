#ifndef __RenderLayer__
#define __RenderLayer__

#include "Layer.hpp"
#include "ui/window.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace world::tile {

  class RenderLayer final : public Layer
    , public ui::Drawable {

  private:
    sf::Sprite m_sprite;

  public:
    RenderLayer(Collision collision = Collision::False, const sf::Sprite &sprite = sf::Sprite());
    void draw(ui::window &window) override;
  };
}// namespace world::tile
#endif