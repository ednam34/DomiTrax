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
                                                  traxGrid grid) {
    colorSprite.setTexture(tuileGraphics.textures[grid.tileNext.index]);

    // Render all tiles
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            TraxTuile tile = grid.tiles[y][x];

            // Create a sprite for the tile
            sf::Sprite sprite;
            sprite.setPosition(tile.getX() * TILE_SIZE,
                               tile.getY() * TILE_SIZE);

            // Set the texture of the sprite based on the state of the tile
            if (tile.state == TileState::Empty) {
                // set the texture to white if the tile is empty
                sprite.setTexture(tuileGraphics.textures[0]);
            } else {
                sprite.setTexture(tuileGraphics.textures[1]);
            }

            window.draw(sprite);
        }
    }

    colorSprite.setPosition(BOARD_WIDTH * TILE_SIZE + 50, 50);
    window.draw(colorSprite);
}

void traxGridGraphics::traxGridGraphics::rotateTile() {}
