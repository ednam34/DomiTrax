#ifndef TRAXGRID_HPP
#define TRAXGRID_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

#include "grid.hpp"
#include "traxTuile.hpp"

const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 500;
const int TILE_SIZE = 50;
const int BOARD_WIDTH = 3;
const int BOARD_HEIGHT = 3;

class traxGrid : public Grid {
   public:
    int width;
    int height;
    TileState currentPlayer;
    TraxTuile tileNext;
    std::array<TilesDetails, 7> tilesDetails;
    traxGrid();
    traxGrid(int width, int height);
    //~traxGrid();
    bool addTraxTuile(int x, int y, TileState player);
    TraxTuile getTraxTuile(int x, int y);
    void printGrid();
    bool checkAdjacentTile(int x, int y, TraxTuile player);
    void setNextTilesDetails(TraxTuile tileNext);
    bool placeTile(int x, int y, TileState player);
    bool isBoardEmpty();
    TraxTuile tiles[10][10];
    int **Board2Matrix();
    void updateTileNext();

   protected:
    // 2d vector of tuiles

   private:
    sf::Texture generateRandomTexture();
    int generateRandomTextureIndex();
    void rotateTile();
};

#endif