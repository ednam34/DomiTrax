#include "hpp/DominoTuileGraphics.hpp"
#include "hpp/DominoTuileGraphics.hpp"


DominoTuileGFX::DominoTuileGFX() {}

DominoTuileGFX::DominoTuileGFX(DominoTuile dominoTuile, int x, int y) {
    this->dominoTuile = dominoTuile;
    this->x = x;
    this->y = y;
}

void DominoTuileGFX::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape rectangle(sf::Vector2f(50, 50));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(x, y);
    target.draw(rectangle);
}