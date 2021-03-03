#include "tilemap.hpp"

#include <memory>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Map.hpp>
#include <iostream>

namespace world::tile
{

constexpr int GROUND_LAYER = 0;
constexpr int COLLISION_LAYER = 1;

tilemap::tilemap(int columns, int rows, int tile_height_in_pixels, int tile_width_in_pixels) : m_num_columns(columns),
                                                                                               m_num_rows(rows),
                                                                                               m_tile_height(tile_height_in_pixels),
                                                                                               m_tile_width(tile_width_in_pixels),
                                                                                               m_tiles(Tiles(columns * rows)),
                                                                                               m_pos(Positions(columns * rows)) {}

tilemap tilemap::load_from_file(std::string name)
{

    tmx::Map tmxmap;
    tmxmap.load(name);
    const auto [tile_width, tile_height] = tmxmap.getTileSize();
    const auto [num_columns, num_rows] = tmxmap.getTileCount();
    const auto tilesetCount = tmxmap.getTilesets().size();
    const auto layerCount = tmxmap.getLayers().size();

    std::cerr << "load_from_file: " << name << ", loaded " << tilesetCount << " tilesets"
              << " and " << layerCount << " layers" << std::endl;
    std::cerr << "num rows: " << num_rows << std::endl;
    std::cerr << "num columns: " << num_columns << std::endl;

    const auto total_tiles = num_columns * num_rows;

    tilemap tm(num_columns, num_rows, tile_height, tile_width);

    /* Populate the ground layer */
    tm.read_and_populate(tmxmap, GROUND_LAYER, LayerType::ground_layer);
    return tm;
}

void tilemap::read_and_populate(const tmx::Map &tmxmap, int LAYER_INDEX, LayerType _layer)
{

    const auto tiles = tmxmap.getLayers()[0]->getLayerAs<tmx::TileLayer>().getTiles();
    const auto collision = tmxmap.getLayers()[1]->getLayerAs<tmx::TileLayer>().getTiles();
    std::cerr << "LAYER_INDEX: " << LAYER_INDEX << " " << tiles.size() << std::endl;
    m_textures[_layer] = std::make_unique<sf::Texture>();
    std::unique_ptr<sf::Texture> &texture = m_textures[_layer];
    texture->loadFromFile(tmxmap.getTilesets()[0].getImagePath());

    const auto [texture_width, texture_height] = texture->getSize();

    // The amount of sprites that exist on a single row, and column
    const auto sprite_count_x = texture_width / m_tile_width;
    const auto sprite_count_y = texture_height / m_tile_height;

    for (int r = 0; r < m_num_rows; r++)
    {
        for (int c = 0; c < m_num_columns; c++)
        {

            // The index in the single-dimension array
            auto index = r * m_num_columns + c;

            sf::Sprite sprite;
            sprite.setTexture(*texture);

            sprite.setPosition(c * m_tile_width, r * m_tile_height);

            m_pos[index] = std::make_pair(c * m_tile_width, r * m_tile_height);

            //This index value comes from the tmx::Map library. It gives ID's starting at a value of 1.
            //This is because the Tiled software that creates the tmx library is written in LUA and starts at 1.
            int ind = tiles[index].ID - 1;

            // The row and column of the the associated tile in the tileset.
            int row = ind / sprite_count_x;
            int col = ind % sprite_count_y;

            //Gets the bounding rectangle in the tileset.
            sf::IntRect ir(col * m_tile_width,
                           row * m_tile_height, m_tile_width, m_tile_height);
            sprite.setTextureRect(ir);

            doFlips(tiles[index].flipFlags, sprite);
            RenderLayer layer(collision[index].ID == 1 ? Collision::True : Collision::False, sprite);

            std::cout << index << " " << ind << " " << r << " " << c << " ";
            std::cout << m_pos[index].first << " " << m_pos[index].second << " " << collision[index].ID << std::endl;

            m_tiles[index].add_layer(_layer, layer);
        }
    }
}

int tilemap::column_count() const
{
    return m_num_columns;
}

int tilemap::row_count() const
{
    return m_num_rows;
}

void tilemap::draw(ui::window &window)
{

    for (int r = 0; r < m_num_rows; r++)
    {
        for (int c = 0; c < m_num_columns; c++)
        {
            auto index = r * m_num_columns + c;
            Tile &t = m_tiles[index];
            t.draw(window);
        }
    }
}

void tilemap::doFlips(std::uint8_t bits, sf::Sprite &sprite)
{
    //0000 = no change
    //0100 = vertical = swap y axis
    //1000 = horizontal = swap x axis
    //1100 = horiz + vert = swap both axes = horiz+vert = rotate 180 degrees
    //0010 = diag = rotate 90 degrees right and swap x axis
    //0110 = diag+vert = rotate 270 degrees right
    //1010 = horiz+diag = rotate 90 degrees right
    //1110 = horiz+vert+diag = rotate 90 degrees right and swap y axis
    if (!(bits & tmx::TileLayer::FlipFlag::Horizontal) &&
        !(bits & tmx::TileLayer::FlipFlag::Vertical) &&
        !(bits & tmx::TileLayer::FlipFlag::Diagonal))
    {
        //Shortcircuit tests for nothing to do
        return;
    }
    else if (!(bits & tmx::TileLayer::FlipFlag::Horizontal) &&
             (bits & tmx::TileLayer::FlipFlag::Vertical) &&
             !(bits & tmx::TileLayer::FlipFlag::Diagonal))
    {
        //0100
        flipY(sprite);
    }
    else if ((bits & tmx::TileLayer::FlipFlag::Horizontal) &&
             !(bits & tmx::TileLayer::FlipFlag::Vertical) &&
             !(bits & tmx::TileLayer::FlipFlag::Diagonal))
    {
        //1000
        flipX(sprite);
    }
    else if ((bits & tmx::TileLayer::FlipFlag::Horizontal) &&
             (bits & tmx::TileLayer::FlipFlag::Vertical) &&
             !(bits & tmx::TileLayer::FlipFlag::Diagonal))
    {
        //1100
        flipY(sprite);
        flipX(sprite);
    }
    else if (!(bits & tmx::TileLayer::FlipFlag::Horizontal) &&
             !(bits & tmx::TileLayer::FlipFlag::Vertical) &&
             (bits & tmx::TileLayer::FlipFlag::Diagonal))
    {
        //0010
        flipD(sprite);
    }
    else if (!(bits & tmx::TileLayer::FlipFlag::Horizontal) &&
             (bits & tmx::TileLayer::FlipFlag::Vertical) &&
             (bits & tmx::TileLayer::FlipFlag::Diagonal))
    {
        //0110
        flipX(sprite);
        flipD(sprite);
    }
    else if ((bits & tmx::TileLayer::FlipFlag::Horizontal) &&
             !(bits & tmx::TileLayer::FlipFlag::Vertical) &&
             (bits & tmx::TileLayer::FlipFlag::Diagonal))
    {
        //1010
        flipY(sprite);
        flipD(sprite);
    }
    else if ((bits & tmx::TileLayer::FlipFlag::Horizontal) &&
             (bits & tmx::TileLayer::FlipFlag::Vertical) &&
             (bits & tmx::TileLayer::FlipFlag::Diagonal))
    {
        //1110
        flipY(sprite);
        flipX(sprite);
        flipD(sprite);
    }
}

void tilemap::flipY(sf::Sprite &sprite)
{
    //Flip Y
    int width = sprite.getTextureRect().width;
    int height = sprite.getTextureRect().height;
    sprite.setTextureRect(sf::IntRect(sprite.getTextureRect().left, sprite.getTextureRect().top + height, width, -height));
}

void tilemap::flipX(sf::Sprite &sprite)
{
    //Flip X
    int width = sprite.getTextureRect().width;
    int height = sprite.getTextureRect().height;

    //  std::cout << "c1: " << sprite.getTextureRect().left + width << " " << sprite.getTextureRect().top << std::endl;
    //  std::cout << "c2: " << sprite.getTextureRect().left << " " << sprite.getTextureRect().top << std::endl;

    sprite.setTextureRect(sf::IntRect(sprite.getTextureRect().left + width, sprite.getTextureRect().top, -width, height));
}

void tilemap::flipD(sf::Sprite &sprite)
{
    //Todo;
    //Diagonal flip
    int width = sprite.getTextureRect().width;
    int height = sprite.getTextureRect().height;
    sprite.setTextureRect(sf::IntRect(width, 0, -width, height));
}

Tile tilemap::pointToTile(const sf::Vector2f &point){

    const int col = point.x / m_tile_width;
    const int row = point.y / m_tile_height;

    return m_tiles[row * m_num_columns + col];
}

} // namespace world::tile