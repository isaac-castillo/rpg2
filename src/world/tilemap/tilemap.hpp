#ifndef __tilemap__
#define __tilemap__
#include <SFML/Graphics/Texture.hpp>

#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>

#include <unordered_map>
#include <vector>
#include <utility>

#include "world/tilemap/tile.hpp"
#include "ui/window.hpp"

namespace world::tile
{

class tilemap : public ui::Drawable
{

    using Textures = std::unordered_map<LayerType, std::unique_ptr<sf::Texture>>;
    using Tiles = std::vector<Tile>;
    using Positions = std::vector<std::pair<int, int>>;

        public : 

    //Factory    
    static tilemap load_from_file(std::string name);
    void draw(ui::window &window) override;

    int row_count() const;
    int column_count() const;

    Tile pointToTile(const sf::Vector2f &point);

private:
    tilemap(int m_num_rows, int m_num_columns, int m_tile_width, int m_tile_height);

    const int m_num_rows{0};
    const int m_num_columns{0};

    const int m_tile_width{0};
    const int m_tile_height{0};

    Textures m_textures;
    Tiles m_tiles;
    Positions m_pos;

    void read_and_populate(const tmx::Map &tmxmap, int LAYER_INDEX, LayerType _layer);
    void populate_ground(const std::vector<tmx::TileLayer::Tile> &tiles);
    void populate_collision(const std::vector<tmx::TileLayer::Tile> &tmxtiles);
    void doFlips(std::uint8_t bits, sf::Sprite &sprite);

    void flipD(sf::Sprite &sprite);
    void flipX(sf::Sprite &sprite);
    void flipY(sf::Sprite &sprite);
};
} // namespace world::tile
#endif