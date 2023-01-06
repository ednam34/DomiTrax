#include <SFML/Graphics.hpp>

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

    bool a = tg1.addTraxTuile(TuileAPlacer.getX(), TuileAPlacer.getY(),
                              TuileAPlacer.state);
    TraxTuile TuileAPlacerBis = TraxTuile(1, 2, 0);
    TuileAPlacerBis.state = TileState::Player2;

    TuileAPlacerBis.tileDetails = {1, 1, 2, 2};
    bool b = tg1.addTraxTuile(TuileAPlacerBis.getX(), TuileAPlacerBis.getY(),
                              TuileAPlacerBis.state);
    TuileAPlacer.tileDetails = {1, 1, 2, 2};
    std::cout << b << std::endl;
    TileState currentPlayer = TileState::Player1;

    traxGridGraphics tgGraphics = traxGridGraphics(tg1, window);
    tg1.tileNext.index = 1;
    while (window.isOpen()) {
        // print checkpath()
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                // check if the click is a left click
                if (event.mouseButton.button != sf::Mouse::Left) {
                    int index = (index + 1) % 7;
                    if (index == 0) {
                        index = 1;
                    }
                    tg1.tileNext.index = index;
                    tg1.updateTileNext();
                    tg1.tileNext.state = currentPlayer;
                    // print state
                    // tg1.changeTileNext(tg1.tileNext.index);
                    //  print a message if the click is not a left click
                    /*std::cout << "Please use the left mouse button."
                              << std::endl;*/
                } else {
                    // Handle a mouse click event
                    int x = event.mouseButton.x / TILE_SIZE;
                    int y = event.mouseButton.y / TILE_SIZE;
                    if (x >= tg1.width || y >= tg1.height || x < 0 || y < 0) {
                        std::cout << "Out of bounds" << std::endl;
                    } else {
                        bool a = tg1.addTraxTuile(x, y, TileState::Player1);

                        // Switch to the other player's turn
                        if (a && currentPlayer == TileState::Player1) {
                            currentPlayer = TileState::Player2;
                            tg1.currentPlayer = TileState::Player2;
                            // print player 2 turn
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

int Domino() {
    dominoGrid dg1 = dominoGrid(10, 10);
    dg1.setGrid();
    dg1.printGrid();
    dg1.getDominoTuile(0, 0).printBorders();
}

int Window() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(700, 500), "SFML window");

    // Start the game loop
    // mainMenuFunc(window)
    if (mainMenuFunc(window) == 1) {
        Trax(window);
    } else if (mainMenuFunc(window) == 0) {
        Domino();
    }
    return 0;
}

int main() {
    int i = Window();
    if (i == 0) {
        std::cout << "0" << std::endl;
    } else if (i == 1) {
        std::cout << "1" << std::endl;
        /*Tuile t1(0, 0, 3);

        // create a grid
        Grid g1(10, 10);
        std::cout << g1.getWidth() << std::endl;
        std::cout << g1.getHeight() << std::endl;

        traxGrid tg1 = traxGrid();
        TraxTuile TuileAPlacer = TraxTuile(1, 1, 0);
        TuileAPlacer.tileDetails = {1, 1, 2, 2};
        TuileAPlacer.state = TileState::Player1;

        bool a = tg1.addTraxTuile(TuileAPlacer.getX(), TuileAPlacer.getY(),
                                  TuileAPlacer.state);
        TraxTuile TuileAPlacerBis = TraxTuile(1, 2, 0);
        TuileAPlacerBis.state = TileState::Player2;

        TuileAPlacerBis.tileDetails = {1, 1, 2, 2};
        bool b =
            tg1.addTraxTuile(TuileAPlacerBis.getX(), TuileAPlacerBis.getY(),
                             TuileAPlacerBis.state);
        TuileAPlacer.tileDetails = {1, 1, 2, 2};
        std::cout << b << std::endl;

        tg1.Board2Matrix();*/

    } else if (i == 2) {
        std::cout << "2" << std::endl;
    }

    return 0;
}