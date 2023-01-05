#include "hpp/grid.hpp"

Grid::Grid() : width(0), height(0) {
}

Grid::Grid(int width, int height) : width(width), height(height) {
}

Grid::~Grid() {
}

int Grid::getWidth() {
    return width;
}

int Grid::getHeight() {
    return height;
}

void Grid::addTuile(Tuile t) {
    tuiles.push_back(t);
}

Tuile Grid::getTuile(int x, int y) {
    for (int i = 0; i < tuiles.size(); i++) {
        if (tuiles[i].getX() == x && tuiles[i].getY() == y) {
            return tuiles[i];
        }
    }
}
