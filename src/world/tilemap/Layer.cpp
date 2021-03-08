#include "Layer.hpp"

namespace world::tile
{

Layer::Layer(Collision isCollisionLayer) : collision(isCollisionLayer)
{
}

bool Layer::is_collision() const
{
    return collision == Collision::True;
}

void Layer::set_collision(Collision collision)
{
    this->collision = collision;
}

} // namespace world::tile