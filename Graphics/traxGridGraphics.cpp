#include "hpp/traxGridGraphics.hpp"
sf::Sprite colorSprite;
traxTuileGraphics tuileGraphics;

traxGridGraphics::traxGridGraphics(traxGrid grid, sf::RenderWindow& window) {
    tuileGraphics.textures[0].loadFromFile("textures/0.png");
    tuileGraphics.textures[1].loadFromFile("textures/1.png");
    tuileGraphics.textures[2].loadFromFile("textures/2.png");
    tuileGraphics.textures[3].loadFromFile("textures/3.png");
    tuileGraphics.textures[4].loadFromFile("textures/4.png");
    tuileGraphics.textures[5].loadFromFile("textures/5.png");
    tuileGraphics.textures[6].loadFromFile("textures/6.png");
}

void traxGridGraphics::traxGridGraphics::renderGG(sf::RenderWindow& window,
                                                  traxGrid grid,
                                                  TileState currentPlayer) {
    int a = grid.tileNext.index;

    colorSprite.setTexture(tuileGraphics.textures[a]);
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            TraxTuile tile = grid.tiles[y][x];
            sf::Sprite sprite;
            sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);

            if (tile.state == TileState::Empty) {
                sprite.setTexture(tuileGraphics.textures[0]);
            } else {
                sprite.setTexture(
                    tuileGraphics.textures[grid.tiles[y][x].index]);
            }

            window.draw(sprite);
        }
    }
    sf::Text playerNameText;

    sf::Font font;
    font.loadFromFile("arialbis.TTF");
    playerNameText.setFont(font);

    if (currentPlayer == TileState::Player1) {
        playerNameText.setFillColor(sf::Color::Blue);

        playerNameText.setString("Joueur 1");
    }
    if (currentPlayer == TileState::Player2) {
        playerNameText.setFillColor(sf::Color::Red);

        playerNameText.setString("Joueur 2");
    }
    playerNameText.setCharacterSize(13);

    sf::Vector2f playerNameTextPosition(
        colorSprite.getPosition().x - 10,
        colorSprite.getPosition().y + colorSprite.getGlobalBounds().height +
            10);
    playerNameText.setPosition(playerNameTextPosition);

    window.draw(playerNameText);
    colorSprite.setPosition(BOARD_WIDTH * TILE_SIZE + 50, 50);
    window.draw(colorSprite);
}

void traxGridGraphics::traxGridGraphics::rotateTile(traxGrid grid) {
    grid.tileNext.index = (grid.tileNext.index + 1) % 7;
}
