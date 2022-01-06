#ifndef __tilemap__
#define __tilemap__
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>

#include <unordered_map>
#include <utility>
#include <vector>

#include "BaseTilemap.hpp"
#include "ui/window.hpp"
#include "world/tilemap/Tile.hpp"

namespace world::tile {

  class Tilemap : public ui::Drawable {

    using Textures = std::unordered_map<LayerType, std::unique_ptr<sf::Texture>>;
    using Tiles = std::vector<Tile>;
    using Positions = std::vector<std::pair<int, int>>;

  public:
    //Factory
    static Tilemap load_from_file(std::string name);
    static Tilemap create_base_tilemap(const BaseTilemap &tilemap);
    Tile pointToTile(sf::Vector2i point) const;
    void draw(ui::window &window) override;

  private:
    Tilemap(const BaseTilemap &tilemap);

    Textures m_textures;
    BaseTilemap baseTilemap;
    Tiles tiles;
    Positions m_pos;

    void read_and_populate(const tmx::Map &tmxmap, int LAYER_INDEX, LayerType _layer);
    void populate_ground(const std::vector<tmx::TileLayer::Tile> &tiles);
    void populate_collision(const std::vector<tmx::TileLayer::Tile> &tmxtiles);
    void doFlips(std::uint8_t bits, sf::Sprite &sprite);

    void flipD(sf::Sprite &sprite);
    void flipX(sf::Sprite &sprite);
    void flipY(sf::Sprite &sprite);
  };
}// namespace world::tile
#endif