#include "hpp/traxTuile.hpp"

TraxTuile::TraxTuile() : Tuile() {
    values = {0, 0, 0, 0};
    tilesDetails = {0, 0, 0, 0};
    index = 0;
}

TraxTuile::TraxTuile(int x, int y, int orientation) : Tuile(x, y, orientation) {
    values = {0, 0, 0, 0};
    tilesDetails = {0, 0, 0, 0};
    index = 0;
    state = TileState::Empty;
}

TraxTuile::~TraxTuile() {}

void TraxTuile::setTilesDetails(TilesDetails tilesDetails) {
    this->tilesDetails = tilesDetails;
}

void TraxTuile::setValues(std::vector<int> values) { this->values = values; }

std::vector<int> TraxTuile::getValues() { return values; }

// Getters and setters
void TraxTuile::setX(int x) { this->x = x; }

void TraxTuile::setY(int y) { this->y = y; }

void TraxTuile::setOrientation(int orientation) {
    this->orientation = orientation;
}

int TraxTuile::getX() { return x; }

int TraxTuile::getY() { return y; }

int TraxTuile::getOrientation() { return orientation; }

void TraxTuile::setNextTilesDetails(TraxTuile tileNext) {
    int index = tileNext.index;
    // print index
    // tileNext.setTexture(generateRandomTexture());
    tileNext.index = index + 1;
    std::cout << "index: " << index << std::endl;
}

// Path: DomiTrax/hpp/grid.hpp