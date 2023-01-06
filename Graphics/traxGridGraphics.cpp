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

// do render
void traxGridGraphics::traxGridGraphics::renderGG(sf::RenderWindow& window,
                                                  traxGrid grid,
                                                  TileState currentPlayer) {
    int a = grid.tileNext.index;

    colorSprite.setTexture(tuileGraphics.textures[a]);
    // Render all tiles
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            TraxTuile tile = grid.tiles[y][x];
            // Create a sprite for the tile
            sf::Sprite sprite;
            sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);

            // Set the texture of the sprite based on the state of the tile
            if (tile.state == TileState::Empty) {
                // set the texture to white if the tile is empty
                sprite.setTexture(tuileGraphics.textures[0]);
            } else {
                sprite.setTexture(
                    tuileGraphics.textures[grid.tiles[y][x].index]);
            }

            window.draw(sprite);
        }
    }
    // Create a sf::Text object for the player name
    sf::Text playerNameText;

    // Set the font for the text
    sf::Font font;
    font.loadFromFile("arialbis.TTF");
    playerNameText.setFont(font);

    // Set the character size and color of the text
    if (currentPlayer == TileState::Player1) {
        playerNameText.setFillColor(sf::Color::Blue);

        // Set the string of the text to be the player name
        playerNameText.setString("Joueur 1");
    }
    if (currentPlayer == TileState::Player2) {
        playerNameText.setFillColor(sf::Color::Red);

        // Set the string of the text to be the player name
        playerNameText.setString("Joueur 2");
    }
    playerNameText.setCharacterSize(13);

    // Set the position of the text to be just under the colorSprite
    sf::Vector2f playerNameTextPosition(
        colorSprite.getPosition().x - 10,
        colorSprite.getPosition().y + colorSprite.getGlobalBounds().height +
            10);
    playerNameText.setPosition(playerNameTextPosition);

    // Draw the text to the window
    window.draw(playerNameText);
    colorSprite.setPosition(BOARD_WIDTH * TILE_SIZE + 50, 50);
    window.draw(colorSprite);
}

void traxGridGraphics::traxGridGraphics::rotateTile(traxGrid grid) {
    grid.tileNext.index = (grid.tileNext.index + 1) % 7;
}
