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

void Layer::set_collision(Collision isCollisionLayer)
{
    collision = isCollisionLayer;
}

} // namespace world::tile