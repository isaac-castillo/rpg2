#include "RenderLayer.hpp"

namespace world::tile
{
RenderLayer::RenderLayer(Collision collision, const sf::Sprite &sprite) : Layer(collision), m_sprite(sprite)
{
}

void RenderLayer::draw(ui::window &window)
{
    window.draw(m_sprite);
}

} // namespace world::tile