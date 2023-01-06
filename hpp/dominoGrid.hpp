#ifndef DOMINOGRID_HPP
#define DOMINOGRID_HPP


#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "dominoTuile.hpp"
#include <iostream>
#include <queue>
#include <random>
#include <vector>

class dominoGrid: public Grid {
    public:
        dominoGrid();
        dominoGrid(int width, int height);
        ~dominoGrid();

        void addDominoTuile(int x, int y, int orientation, std::vector<Borders> borders);
        DominoTuile getDominoTuile(int x, int y);
        void printGrid();
        void printBorders();
        void printRandomBorders();
        void setRandomBorders();

    
    protected:
        // 2d vector of tuiles
        std::vector<DominoTuile> tuiles;
        std::vector<Borders> randomBorders;
        DominoTuile tiles[10][10];
};






#endif  // DOMINOGRID_HPP