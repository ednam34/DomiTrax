#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <string>
#include <vector>
#include "tuile.hpp"

class Grid{

    public:
        Grid();
        Grid(int width, int height);
        virtual ~Grid();
        int getWidth();
        int getHeight();
        virtual void addTuile(Tuile t);
        virtual Tuile getTuile(int x, int y);
    protected:
        const int width;
        const int height;
        //2d vector of tuiles
        std::vector<Tuile> tuiles;

};


#endif  // GRID_HPP