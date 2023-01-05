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

TraxTuile::~TraxTuile() {
}

void TraxTuile::setTilesDetails(TilesDetails tilesDetails) {
    this->tilesDetails = tilesDetails;
}

void TraxTuile::setValues(std::vector<int> values) {
    this->values = values;
}

std::vector<int> TraxTuile::getValues() {
    return values;
}

// Path: DomiTrax/hpp/grid.hpp