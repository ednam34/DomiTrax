#include "hpp/DominoTuileGraphics.hpp"
#include "hpp/DominoTuileGraphics.hpp"


DominoTuileGFX::DominoTuileGFX() {}

DominoTuileGFX::DominoTuileGFX(DominoTuile dominoTuile, int x, int y) {
    this->dominoTuile = dominoTuile;
    this->x = x;
    this->y = y;
    //dominoTuile.printBorders();
    this->values = dominoTuile.getValues();

}

void DominoTuileGFX::setTextPosition(sf::RenderTarget& target) {
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text textN[3];
    sf::Text textS[3];
    sf::Text textE[3];
    sf::Text textW[3];
    for (int i = 0; i < 3; i++) {
        textN[i].setFont(font);
        textS[i].setFont(font);
        textE[i].setFont(font);
        textW[i].setFont(font);
        textN[i].setCharacterSize(9);
        textS[i].setCharacterSize(9);
        textE[i].setCharacterSize(9);
        textW[i].setCharacterSize(9);
        textN[i].setFillColor(sf::Color::Black);
        textS[i].setFillColor(sf::Color::Black);
        textE[i].setFillColor(sf::Color::Black);
        textW[i].setFillColor(sf::Color::Black);
    }

    textN[0].setString(std::to_string(values[0].a));
    textN[1].setString(std::to_string(values[0].b));
    textN[2].setString(std::to_string(values[0].c));
    textS[0].setString(std::to_string(values[2].a));
    textS[1].setString(std::to_string(values[2].b));
    textS[2].setString(std::to_string(values[2].c));
    textE[0].setString(std::to_string(values[1].a));
    textE[1].setString(std::to_string(values[1].b));
    textE[2].setString(std::to_string(values[1].c));
    textW[0].setString(std::to_string(values[3].a));
    textW[1].setString(std::to_string(values[3].b));
    textW[2].setString(std::to_string(values[3].c));



   textN[0].setPosition(
        (50 / 1.5 - textN[0].getGlobalBounds().width / 1.5) + x, 10 + y);
    textN[1].setPosition(
        (50 / 2 - textN[1].getGlobalBounds().width / 2) + x, 10 + y);
    textN[2].setPosition(
        (50 / 3 - textN[2].getGlobalBounds().width / 3) + x, 10 + y);

    textS[0].setPosition(
        (50 - textS[0].getGlobalBounds().width - 10) + x,
        (50 / 1.5 - textS[0].getGlobalBounds().height / 1.5) + y);
    textS[1].setPosition(
        (50 - textS[1].getGlobalBounds().width - 10) + x,
        (50 / 2 - textS[1].getGlobalBounds().height / 2) + y);
    textS[2].setPosition(
        (50 - textS[2].getGlobalBounds().width - 10) + x,
        (50 / 3 - textS[2].getGlobalBounds().height / 3) + y);

    textE[0].setPosition(
        (50 / 1.5 - textE[0].getGlobalBounds().width / 1.5) + x,
        (50 - textE[0].getGlobalBounds().height - 10) + y);
    textE[1].setPosition(
        (50 / 2 - textE[1].getGlobalBounds().width / 2) + x,
        (50 - textE[1].getGlobalBounds().height - 10) + y);
    textE[2].setPosition(
        (50 / 3 - textE[2].getGlobalBounds().width / 3) + x,
        (50 - textE[2].getGlobalBounds().height - 10) + y);

    textW[0].setPosition(
        10 + x,
        (50 / 1.5 - textW[0].getGlobalBounds().height / 1.5) + y);
    textW[1].setPosition(
        10 + x, (50 / 2 - textW[1].getGlobalBounds().height / 2) + y);
    textW[2].setPosition(
        10 + x, (50 / 3 - textW[2].getGlobalBounds().height / 3) + y);

    target.draw(textN[0]);
    target.draw(textN[1]);
    target.draw(textN[2]);
    target.draw(textS[0]);
    target.draw(textS[1]);
    target.draw(textS[2]);
    target.draw(textE[0]);
    target.draw(textE[1]);
    target.draw(textE[2]);
    target.draw(textW[0]);
    target.draw(textW[1]);
    target.draw(textW[2]);
}


void DominoTuileGFX::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape rectangle(sf::Vector2f(50, 50));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(x, y);
    //get the value of the domino tuile
    //draw the domino tuile
    

    //draw the borders

    target.draw(rectangle);
 
}