#ifndef __tilemap__
#define __tilemap__
#include <SFML/Graphics/Texture.hpp>
#include <unordered_map>
#include "tile.hpp"
#include <vector>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Map.hpp>
#include "ecs/entity.hpp"
#include <utility>
#include "ui/window.hpp"

namespace world {


    class tilemap {

        public:

            tilemap();
            void load_from_file(std::string name);
            void draw_tiles(ui::window &window);
            
        private:
            int m_num_rows;
            int m_num_columns;

            int m_tile_width;
            int m_tile_height;

            std::unordered_map<layer, sf::Texture> m_textures;

            std::vector<tile> m_tiles;
            std::vector<std::pair<int,int>> m_pos;

            void populate_ground(const std::vector<tmx::TileLayer::Tile> &tiles);
            void populate_collision(const std::vector<tmx::TileLayer::Tile> &tmxtiles);
    };

};
#endif