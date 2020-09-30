#include "tilemap.hpp"

namespace world {


    tilemap::tilemap() {
        
    }
    
    void tilemap::load_from_file(std::string name){
        tmx::Map tmxmap;
        tmxmap.load(name);

        m_tile_width = tmxmap.getTileSize().x;
        m_tile_height = tmxmap.getTileSize().y;

        m_num_rows = tmxmap.getTileCount().y;
        m_num_columns = tmxmap.getTileCount().x;

        m_tiles = std::vector<tile>(m_num_rows * m_num_columns);
        m_pos = std::vector<std::pair<int, int>>(m_num_rows * m_num_columns);
        
        const auto ground = tmxmap.getLayers()[0]->getLayerAs<tmx::TileLayer>().getTiles();
        sf::Texture ground_texture;
        ground_texture.loadFromFile(tmxmap.getTilesets()[0].getImagePath());
        m_textures[layer::ground_layer] =  ground_texture;

        populate_ground(ground);

        if(tmxmap.getLayers().size() >= 2){
            const auto &collision = tmxmap.getLayers()[1]->getLayerAs<tmx::TileLayer>().getTiles();
            sf::Texture collision_texture;

            if (tmxmap.getTilesets().size() >= 2){
                collision_texture.loadFromFile(tmxmap.getTilesets()[1].getImagePath());
                m_textures[layer::collision_layer] = collision_texture;
            }
            else{

            }

          //  populate_collision(collision);
        }

    }

    void tilemap::populate_ground(const std::vector<tmx::TileLayer::Tile> &tmxtiles)
    {

        auto & texture = m_textures[layer::ground_layer];

        auto image_width = texture.getSize().x / m_tile_width;
        auto image_height = texture.getSize().y / m_tile_height;

        for (int r = 0; r < m_num_rows; r++)
        {
            for (int c = 0; c < m_num_columns; c++)
            {
                auto index = r * m_num_columns + c;


                sf::Sprite sprite;
                sprite.setTexture(texture);
                sprite.setPosition(c * m_tile_width, r * m_tile_height); //sets x_position (width) before y_position (height)
                
                m_pos[index] = std::make_pair(c * m_tile_width, r * m_tile_height);

                int ind = tmxtiles[index].ID - 1;
                int row = ind / image_width;
                int col = ind % image_width;
                sf::IntRect ir(col * m_tile_width,
                               row * m_tile_height, m_tile_width, m_tile_height);
                sprite.setTextureRect(ir);


                layer_state state(sprite, false);
                m_tiles[index].add_to_layer(layer::ground_layer, state);
            }
        }
    }

    void tilemap::populate_collision(const std::vector<tmx::TileLayer::Tile> &tmxtiles){

        auto &texture = m_textures[layer::collision_layer];

        auto image_width = texture.getSize().x / m_tile_width;
        auto image_height = texture.getSize().y / m_tile_height;

        for (int r = 0; r < m_num_rows; r++)
        {
            for (int c = 0; c < m_num_columns; c++)
            {
                auto index = r * m_num_columns + c;

                sf::Sprite sprite;
                sprite.setTexture(texture);
                sprite.setPosition(c * m_tile_width, r * m_tile_height); //sets x_position (width) before y_position (height)

                m_pos[index] = std::make_pair(c * m_tile_width, r * m_tile_height);

                int ind = tmxtiles[index].ID - 1;
                int row = ind / image_width;
                int col = ind % image_width;
                sf::IntRect ir(col * m_tile_width,
                               row * m_tile_height, m_tile_width, m_tile_height);
                sprite.setTextureRect(ir);
                layer_state state(sprite, false);

                m_tiles[index].add_to_layer(layer::collision_layer, state);
            }
        }
    }

    void tilemap::draw_tiles(ui::window &window){

        for (int r = 0; r < m_num_rows; r++)
        {
            for (int c = 0; c < m_num_columns; c++)
            {

                auto index = r * m_num_columns + c;
                tile &t = m_tiles[index];
                t.draw(window);



            }
        }
    }
}