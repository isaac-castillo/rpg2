#ifndef __component_input_player__
#define __component_input_player__

#include "component_input.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "util/moving.hpp"

namespace ecs {
    
    class component_input_player : public component_input {

        void update(entity &entity, float delta) override;
        void receive() override;
        
    };

}


#endif
