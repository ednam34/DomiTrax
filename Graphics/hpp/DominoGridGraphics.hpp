#ifndef DOMINOGRIDGRAPHICS_HPP
#define DOMINOGRIDGRAPHICS_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>

#include "../../hpp/dominoGrid.hpp"
#include "../../hpp/dominoTuile.hpp"
#include "DominoTuileGraphics.hpp"

class DominoGridGFX {
   public:
    DominoGridGFX();
    void drawGridDominoTuile(sf::RenderWindow& window, dominoGrid grid);
};

#endif