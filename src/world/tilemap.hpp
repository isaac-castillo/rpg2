#include <map>

#include "tile.hpp"

namespace world {


class tilemap {

    public:

        tilemap();

    private:
        int num_rows;
        int num_columns;

        std::vector<tile> tiles;

};

};