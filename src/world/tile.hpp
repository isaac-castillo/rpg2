#include <map>

#include "world/layer.hpp"
#include "world/ecs/entity.hpp"
namespace world {
class tile {
 
 
    std::map<layer, ecs::entity> layers; 

    public:
        void add_layer(layer layer);
    



    };

}