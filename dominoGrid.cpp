#include "hpp/dominoGrid.hpp"

dominoGrid::dominoGrid() : Grid() {}

dominoGrid::dominoGrid(int width, int height) : Grid(width, height) {}

dominoGrid::~dominoGrid() {}

void dominoGrid::addDominoTuile(int x, int y, int orientation,
                                std::vector<Borders> borders) {
    DominoTuile t(x, y, orientation, borders);
    tiles[x][y] = t;
}

DominoTuile dominoGrid::getDominoTuile(int x, int y) { return tiles[x][y]; }

void dominoGrid::printGrid() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tiles[i][j].isBoardEmpty() == true) {
                std::cout << "0 ";
            } else {
                std::cout << "1 ";
            }
            {}
        }
        std::cout << std::endl;
    }
}

void dominoGrid::printBorders() {
    for (int i = 0; i < tuiles.size(); i++) {
        std::cout << "x: " << tuiles[i].getX() << " y: " << tuiles[i].getY()
                  << " orientation: " << tuiles[i].getOrientation()
                  << std::endl;
        tuiles[i].printBorders();
    }
}

void dominoGrid::printRandomBorders() {
    for (int i = 0; i < randomBorders.size(); i++) {
        std::cout << "a: " << randomBorders[i].a << " b: " << randomBorders[i].b
                  << " c: " << randomBorders[i].c << std::endl;
    }
}

void dominoGrid::setRandomBorders() {
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

void dominoGrid::setGrid() {
    std::vector<Borders> bors;
    for (int i = 0; i < 2; i++) {
        bors.push_back(Borders{3, 2, 1});
        bors.push_back(Borders{4, 8, 6});
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            DominoTuile t(i, j, 0, bors);
            t.setIsEmpty(true);
            tiles[i][j] = t;
            tiles[i][j].printBorders();
        }
    }
}