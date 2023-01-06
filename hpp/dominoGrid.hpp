#ifndef DOMINOGRID_HPP
#define DOMINOGRID_HPP


#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include <iostream>
#include <queue>
#include <random>
#include <vector>

class dominoGrid: public Grid {
    public:
        dominoGrid();
        dominoGrid(int width, int height);
        ~dominoGrid();
        
};






#endif  // DOMINOGRID_HPP