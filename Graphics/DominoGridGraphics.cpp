#include "hpp/DominoTuileGraphics.hpp"
#include "hpp/DominoGridGraphics.hpp"
#include "../hpp/dominoGrid.hpp"



DominoGridGFX::DominoGridGFX() {}



void DominoGridGFX::drawGridDominoTuile (sf::RenderWindow &window, dominoGrid grid) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            DominoTuileGFX dominoTuileGFX = DominoTuileGFX(grid.getDominoTuile(i,j), i * 50, j * 50);
            window.draw(dominoTuileGFX);
            dominoTuileGFX.setTextPosition(window);
        }
    }
}

