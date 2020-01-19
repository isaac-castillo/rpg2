#ifndef __window__
#define __window__
#include <SFML/Graphics/RenderWindow.hpp>

namespace ui {
    class window : public sf::RenderWindow {


        const int WIDTH = 600;
        const int HEIGHT = 400;

        public:
            window();
            static std::unique_ptr<window> default_window();


    };
}

#endif 
