#include "hpp/dominoGrid.hpp"

dominoGrid::dominoGrid() : Grid() {}

dominoGrid::dominoGrid(int width, int height) : Grid(width, height) {}

dominoGrid::~dominoGrid() {}

void dominoGrid::addDominoTuile(int x, int y, int orientation,
                                std::vector<Borders> borders) {
    DominoTuile t(x, y, orientation, borders);
    tiles[x][y] = t;
}

void dominoGrid::setRandomTile() {
    setRandomBorders();
    // take 4 random borders from the vector of random borders and put them in a
    // vector of borders
    std::vector<Borders> bordersVector = {
        randomBorders[rand() % 10], randomBorders[rand() % 10],
        randomBorders[rand() % 10], randomBorders[rand() % 10]};

    // create a dominoTuile
    DominoTuile t(0, 0, 0, bordersVector);
    t.setIsEmpty(false);
    // add the dominoTuile to the grid
    randomTile.setIsEmpty(false);
    randomTile = t;
}

void dominoGrid::addNextDomino(int x, int y) {
    setRandomBorders();
    // take 4 random borders from the vector of random borders and put them in a
    // vector of borders
    this->randomTile.setX(x);
    this->randomTile.setY(y);

    // add the dominoTuile to the grid
    tiles[x][y] = randomTile;
}

void dominoGrid::addDominoTuile(DominoTuile t) {
    // check if the borders of t are the same as the borders of the tiles in x
    // and y +1 and -1 and x+1 and -1 and y= if they are the same, then the tile
    // is added to the grid
    tiles[t.getX()][t.getY()] = t;
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