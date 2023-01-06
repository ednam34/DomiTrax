#include <SFML/Graphics.hpp>

#include "Graphics/hpp/DominoGridGraphics.hpp"
#include "Graphics/hpp/DominoTuileGraphics.hpp"
#include "Graphics/hpp/traxGridGraphics.hpp"
#include "hpp/dominoGrid.hpp"
#include "hpp/grid.hpp"
#include "hpp/traxGrid.hpp"
#include "hpp/traxTuile.hpp"
#include "hpp/tuile.hpp"
#include "mainScreen.cpp"

int Trax(sf::RenderWindow& window) {
    traxGrid tg1 = traxGrid();
    TraxTuile TuileAPlacer = TraxTuile(1, 1, 0);
    TuileAPlacer.tileDetails = {1, 1, 2, 2};
    TuileAPlacer.state = TileState::Player1;

    TileState currentPlayer = TileState::Player1;

    traxGridGraphics tgGraphics = traxGridGraphics(tg1, window);
    tg1.tileNext.index = 1;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button != sf::Mouse::Left) {
                    int index = (index + 1) % 7;
                    if (index == 0) {
                        index = 1;
                    }
                    tg1.tileNext.index = index;
                    tg1.updateTileNext();
                    tg1.tileNext.state = currentPlayer;
                } else {
                    int x = event.mouseButton.x / TILE_SIZE;
                    int y = event.mouseButton.y / TILE_SIZE;
                    if (x >= tg1.width || y >= tg1.height || x < 0 || y < 0) {
                        std::cout << "Out of bounds" << std::endl;
                    } else {
                        bool a = tg1.addTraxTuile(x, y, TileState::Player1);

                        if (a && currentPlayer == TileState::Player1) {
                            currentPlayer = TileState::Player2;
                            tg1.currentPlayer = TileState::Player2;
                            std::cout << "Player 2 turn" << std::endl;
                        } else if (a && currentPlayer == TileState::Player2) {
                            currentPlayer = TileState::Player1;
                            tg1.currentPlayer = TileState::Player1;
                            std::cout << "Player 1 turn" << std::endl;
                        }
                    }
                }
            }
        }
        window.clear();
        tgGraphics.renderGG(window, tg1, currentPlayer);
        window.display();
    }

    return 0;
}

int Domino(sf::RenderWindow& window) {
    dominoGrid dg1 = dominoGrid(10, 10);
    dg1.setRandomTile();
    dg1.setGrid();
    dg1.printGrid();
    //create a dominoTuile
    Borders borders = Borders{1, 1, 2};
    //create a vector of borders
    std::vector<Borders> bordersVector = {borders,borders,borders,borders};
    DominoTuile TuileAPlacer = DominoTuile(1, 1, 0, bordersVector);
    dg1.addDominoTuile(1, 1, 0, bordersVector);

    DominoGridGFX dgGraphics = DominoGridGFX();
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button != sf::Mouse::Left){
                    int x = event.mouseButton.x / TILE_SIZE;
                    int y = event.mouseButton.y / TILE_SIZE;
                    dg1.addNextDomino(x, y);
                    dg1.setRandomTile();
                    
                }
            }
        }

        window.clear();
        DominoTuileGFX TuileAPlacerGFX = DominoTuileGFX(dg1.randomTile, BOARD_WIDTH * TILE_SIZE + 50,50);
        window.draw(TuileAPlacerGFX);
        TuileAPlacerGFX.setTextPosition(window);
        dgGraphics.drawGridDominoTuile(window, dg1);
        //create a dominoTuileGFx and draw it
       
        window.display();
    }
    return 0;
}

int Window() {
    sf::RenderWindow window(sf::VideoMode(700, 500), "SFML window");

    if (mainMenuFunc(window) == 1) {
        Trax(window);
    } else if (mainMenuFunc(window) == 0) {
        Domino(window);
    }
    return 0;
}

int main() {
    int i = Window();
    if (i == 0) {
        std::cout << "0" << std::endl;
    } else if (i == 1) {
        std::cout << "1" << std::endl;

    } else if (i == 2) {
        std::cout << "2" << std::endl;
    }

    return 0;
}