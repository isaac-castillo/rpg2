#ifndef __layer_state__
#define __layer_state__

namespace world::tile {

enum class LayerType
{
    ground_layer,
    middle_layer,
    top_layer
};


enum class Collision {
    True,
    False
};

class Layer
{

private:
    Collision collision{ Collision::False };

public:
    explicit Layer(Collision collision = Collision::False);
    bool is_collision() const;
    void set_collision(Collision collision);

    };
}
#endif