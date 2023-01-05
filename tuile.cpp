#include "hpp/tuile.hpp"


Tuile::Tuile() {
    x = 0;
    y = 0;
    orientation = 0;
}

Tuile::Tuile(int x, int y, int orientation) {
    this->x = x;
    this->y = y;
    this->orientation = orientation;
}

Tuile::~Tuile() {
}

void Tuile::setX(int x) {
    this->x = x;
}

void Tuile::setY(int y) {
    this->y = y;
}

void Tuile::setOrientation(int orientation) {
    this->orientation = orientation;
}

void Tuile::setState(TileState state) {
    this->state = state;
}

int Tuile::getX() {
    return x;
}

int Tuile::getY() {
    return y;
}

int Tuile::getOrientation() {
    return orientation;
}