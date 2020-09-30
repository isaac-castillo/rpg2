#ifndef __component_input__
#define __component_input__
#include "component.hpp"
#include "entity.hpp"


namespace ecs{ 

class entity;
class component_input : public component {
    
    public:

        virtual void update(entity &entity, float delta) = 0;
};

}
#endif