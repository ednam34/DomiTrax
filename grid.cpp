#include "hpp/grid.hpp"

Grid::Grid() : width(0), height(0) {}

Grid::Grid(int width, int height) : width(width), height(height) {}

Grid::~Grid() {}

int Grid::getWidth() { return width; }

int Grid::getHeight() { return height; }
