#include "hpp/dominoGrid.hpp"


dominoGrid::dominoGrid() : Grid() {}

dominoGrid::dominoGrid(int width, int height) : Grid(width, height) {}

dominoGrid::~dominoGrid() {}

void dominoGrid::addDominoTuile(int x, int y, int orientation, std::vector<Borders> borders) {
    DominoTuile t(x, y, orientation, borders);
    tuiles.push_back(t);
}

DominoTuile dominoGrid::getDominoTuile(int x, int y) {
    for (int i = 0; i < tuiles.size(); i++) {
        if (tuiles[i].getX() == x && tuiles[i].getY() == y) {
            return tuiles[i];
        }
    }
    // Return null
    return DominoTuile();
}

void dominoGrid::printGrid() {
    for (int i = 0; i < tuiles.size(); i++) {
        std::cout << "x: " << tuiles[i].getX() << " y: " << tuiles[i].getY() << " orientation: " << tuiles[i].getOrientation() << std::endl;
    }
}

void dominoGrid::printBorders() {
    for (int i = 0; i < tuiles.size(); i++) {
        std::cout << "x: " << tuiles[i].getX() << " y: " << tuiles[i].getY() << " orientation: " << tuiles[i].getOrientation() << std::endl;
        tuiles[i].printBorders();
    }
}

void dominoGrid::printRandomBorders() {
    for (int i = 0; i < randomBorders.size(); i++) {
        std::cout << "a: " << randomBorders[i].a << " b: " << randomBorders[i].b << " c: " << randomBorders[i].c << std::endl;
    }
}

void dominoGrid::setRandomBorders() {
    //generate 10 random borders
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 6);
    for (int i = 0; i < 10; i++) {
        Borders b;
        b.a = dis(gen);
        b.b = dis(gen);
        b.c = dis(gen);
        randomBorders.push_back(b);
    }
}