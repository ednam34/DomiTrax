#ifndef DOMINOTUILEGRAPHICS_HPP
#define DOMINOTUILEGRAPHICS_HPP

#include "../../hpp/dominoTuile.hpp"
#include "../../hpp/dominoGrid.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <random>

class DominoTuileGFX : public sf::Drawable {

    public:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        DominoTuileGFX();
        DominoTuileGFX(DominoTuile dominoTuile, int x, int y);
        void setTextPosition(sf::RenderTarget& target);
    protected:
        DominoTuile dominoTuile;
        int x;
        int y;
        std::vector<Borders> values;

};


#endif