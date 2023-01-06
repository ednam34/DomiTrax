#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <string>
#include <vector>

#include "tuile.hpp"

class Grid {
   public:
    Grid();
    Grid(int width, int height);
    virtual ~Grid();
    int getWidth();
    int getHeight();

   protected:
    const int width;
    const int height;
    Tuile tiles[6][8];
    std::vector<Tuile> tuiles;
};

#endif