#include "window.hpp"

namespace ui {

    
    window::window(){
        
    }    

    std::unique_ptr<window> window::default_window(){

        return std::make_unique<window>();
    }



}