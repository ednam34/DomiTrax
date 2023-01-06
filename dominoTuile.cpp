#include "hpp/dominoTuile.hpp"


DominoTuile::DominoTuile() : Tuile() {
    this->values = {};

}

DominoTuile::DominoTuile(int x, int y, int orientation, std::vector<Borders> values) : Tuile(x, y, orientation) {
    this->values = values;
    isEmpty = false;
}

DominoTuile::~DominoTuile() {}

void DominoTuile::setX(int x) {
    this->x = x;
}

void DominoTuile::setY(int y) {
    this->y = y;
}

void DominoTuile::setOrientation(int orientation) {
    this->orientation = orientation;
}   

int DominoTuile::getX() {
    return this->x;
}

int DominoTuile::getY() {
    return this->y;
}

std::vector<Borders> DominoTuile::getBorders() {
    return this->values;
}

int DominoTuile::getOrientation() {
    return this->orientation;
}

void DominoTuile::setValues(std::vector<Borders> values) {
    this->values = values;
}

std::vector<Borders> DominoTuile::getValues() {
    return this->values;
}

void DominoTuile::printBorders() {
    std::cout << "a: " << this->values[0].a << " b: " << this->values[0].b << " c: " << this->values[0].c << std::endl;
    std::cout << "a: " << this->values[1].a << " b: " << this->values[1].b << " c: " << this->values[1].c << std::endl;
    std::cout << "a: " << this->values[2].a << " b: " << this->values[2].b << " c: " << this->values[2].c << std::endl;
    std::cout << "a: " << this->values[3].a << " b: " << this->values[3].b << " c: " << this->values[3].c << std::endl;
}

bool DominoTuile::isBoardEmpty() {
    return isEmpty;
}

void DominoTuile::setIsEmpty(bool isEmpty) {
    this->isEmpty = isEmpty;
}




