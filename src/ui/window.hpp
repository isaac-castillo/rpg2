#ifndef __window__
#define __window__
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace ui {

  class window : public sf::RenderWindow {

  private:
    static constexpr int WIDTH = 600;
    static constexpr int HEIGHT = 400;
    std::vector<sf::Sprite> m_drawables{};

  public:
    static window default_window();
    window();
    void add_sprite(sf::Sprite &sprite);
    void draw_sprites();
    void clear_window();
  };

  class Drawable {

  public:
    virtual void draw(ui::window &) = 0;
    virtual ~Drawable() = default;
  };
}// namespace ui

#endif
