#ifndef DOMINOGRIDGRAPHICS_HPP
#define DOMINOGRIDGRAPHICS_HPP
#include "../../hpp/dominoTuile.hpp"
#include "../../hpp/dominoGrid.hpp"
#include "DominoTuileGraphics.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>


class DominoGridGFX{
    public:
        DominoGridGFX();
        void drawGridDominoTuile(sf::RenderWindow& window, dominoGrid grid);
};


#endif  // DOMINOTUILEGRAPHICS_HPP