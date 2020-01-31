#ifndef __window__
#define __window__
#include <SFML/Graphics/RenderWindow.hpp>

namespace ui {
    class window : public sf::RenderWindow {


        private:
            static const int WIDTH = 600;
            static const int HEIGHT = 400;

        public:
            static std::unique_ptr<window> default_window();
            window();


    };
}

#endif 
