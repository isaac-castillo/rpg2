#ifndef __base_tilemap__
#define __base_tilemap__

#include "BaseTile.hpp"
#include <vector>

namespace world::tile {

class BaseTilemap
{


private:
  const int m_num_columns{ 0 };
  const int m_num_rows{ 0 };

  const int m_tile_height{ 0 };
  const int m_tile_width{ 0 };


public:
  BaseTilemap(int columns, int rows, int tile_height_in_pixels, int tile_width_in_pixels) : m_num_columns(columns),
                                                                                            m_num_rows(rows),
                                                                                            m_tile_height(tile_height_in_pixels),
                                                                                            m_tile_width(tile_width_in_pixels)

  {
  }


  int column_count() const
  {
    return m_num_columns;
  }

  int row_count() const
  {
    return m_num_rows;
  }

  int tile_width() const
  {
    return m_tile_width;
  }

  int tile_height() const
  {
    return m_tile_height;
  }

  int pointToIndex(const sf::Vector2i &point) const
  {

    const int col = point.x / tile_width();
    const int row = point.y / tile_height();

    return row * column_count() + col;
  }
};
}// namespace world::tile


#endif
