#include "hpp/traxGrid.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

traxGrid::traxGrid() : Grid(500, 700) {
    // initialize the tiles
    tilesDetails[0] = {0, 0, 0, 0};
    tilesDetails[1] = {1, 1, 2, 2};
    tilesDetails[2] = {2, 2, 1, 1};
    tilesDetails[3] = {1, 2, 1, 2};
    tilesDetails[4] = {1, 2, 2, 1};
    tilesDetails[5] = {2, 1, 2, 1};
    tilesDetails[6] = {2, 1, 1, 2};
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            tiles[i][j].state = TileState::Empty;
            tiles[i][j].tileDetails.BorderBot = 0;
            tiles[i][j].tileDetails.BorderLeft = 0;
            tiles[i][j].tileDetails.BorderRight = 0;
            tiles[i][j].tileDetails.BorderTop = 0;
        }
    }

    tileNext = TraxTuile(0, 0, 0);
    tileNext.index = 1;
    updateTileNext();

    // print with matrix
}

void traxGrid::updateTileNext() {
    tileNext.setNextTilesDetails(tileNext);
    tileNext.state = TileState::Player1;
    tileNext.tileDetails = tilesDetails[tileNext.index];
    tileNext.setOrientation(0);
}

bool traxGrid::isBoardEmpty() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            if (tiles[i][j].state != TileState::Empty) {
                return false;
            }
        }
    }
    return true;
}

TraxTuile traxGrid::getTraxTuile(int x, int y) { return tiles[x][y]; }

bool traxGrid::checkAdjacentTile(int x, int y, TraxTuile player) {
    if (isBoardEmpty()) {
        return true;
    }
    int adjacentTiles = 0;
    int NextTo = 0;
    // print the tile details
    // std::cout << "BorderTop: " << tiles[y][x - 1].tileDetails.BorderTop
    //<< std::endl;
    // std::cout << "BorderBot: " << tiles[y][x - 1].tileDetails.BorderBot
    //<< std::endl;
    std::cout << "BorderLeftACTUAL: " << tiles[y][x].tileDetails.BorderLeft
              << std::endl;
    std::cout << "BorderLeft-1: " << tiles[y][x - 1].tileDetails.BorderLeft
              << std::endl;
    std::cout << "BorderRight: " << tiles[y][x].tileDetails.BorderRight
              << std::endl;
    std::cout << "BorderRight+1: " << tiles[y][x + 1].tileDetails.BorderRight
              << std::endl;
    std::cout << "BorderTop: " << tiles[y][x].tileDetails.BorderTop
              << std::endl;
    std::cout << "BorderTop+1: " << tiles[y - 1][x].tileDetails.BorderTop
              << std::endl;
    std::cout << "BorderBot: " << tiles[y][x].tileDetails.BorderBot
              << std::endl;
    std::cout << "BorderBot +1 : " << tiles[y + 1][x].tileDetails.BorderBot
              << std::endl;

    // std::cout << "BorderRight: " << tiles[y][x -
    // 1].tileDetails.BorderRight
    //<< std::endl;
    // print x and yc
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    // print
    if ((x > 0 && tiles[y][x - 1].state != TileState::Empty &&
         tileNext.tileDetails.BorderLeft ==
             tiles[y][x - 1].tileDetails.BorderRight) ||
        (x > 0 && tiles[y][x - 1].state == TileState::Empty) || (x == 0)) {
        if (tiles[y][x - 1].state != TileState::Empty && x != 0) {
            NextTo++;
        }
        // print premier argument passé
        std::cout << "1er OK" << std::endl;
        adjacentTiles++;
    }
    if ((x < BOARD_WIDTH - 1 && tiles[y][x + 1].state != TileState::Empty &&
         tileNext.tileDetails.BorderRight ==
             tiles[y][x + 1].tileDetails.BorderLeft) ||
        (x < BOARD_WIDTH - 1 && tiles[y][x + 1].state == TileState::Empty) ||
        (x == BOARD_WIDTH - 1)) {
        if (x != BOARD_WIDTH - 1 && tiles[y][x + 1].state != TileState::Empty) {
            NextTo++;
        }
        // print deuxieme argument passé
        std::cout << "2eme OK" << std::endl;
        adjacentTiles++;
    }
    if ((y > 0 && tiles[y - 1][x].state != TileState::Empty &&
         tileNext.tileDetails.BorderTop ==
             tiles[y - 1][x].tileDetails.BorderBot) ||
        (y > 0 && tiles[y - 1][x].state == TileState::Empty) || (y == 0)) {
        if (tiles[y - 1][x].state != TileState::Empty && y != 0) {
            NextTo++;
        }
        // print troisieme argument passé
        std::cout << "3eme OK" << std::endl;
        adjacentTiles++;
    }
    if ((y < BOARD_HEIGHT - 1 && tiles[y + 1][x].state != TileState::Empty &&
         tileNext.tileDetails.BorderBot ==
             tiles[y + 1][x].tileDetails.BorderTop) ||
        (y < BOARD_HEIGHT - 1 && tiles[y + 1][x].state == TileState::Empty) ||
        (y == BOARD_HEIGHT - 1)) {
        if (y != BOARD_HEIGHT - 1 &&
            tiles[y + 1][x].state != TileState::Empty) {
            NextTo++;
        }
        // print quatrieme argument passé
        std::cout << "4eme OK" << std::endl;
        adjacentTiles++;
    }
    std::cout << "NexTO: " << NextTo << std::endl;
    if (adjacentTiles == 4 && NextTo > 0) {
        return true;
    } else {
        return false;
    }
}

bool traxGrid::addTraxTuile(int x, int y, TileState player) {
    if (checkAdjacentTile(x, y, tiles[y][x]) == false) {
        std::cout << "Cannot place a tile on this tile." << std::endl;
        return false;
    }
    // Check if the tile is empty
    if (tiles[y][x].state == TileState::Empty) {
        // Place the tile
        tiles[y][x].state = player;
        // Get the texture of colorSprite and put it in the tile
        tiles[y][x].tileDetails = tileNext.tileDetails;
        // tiles[y][x].Tilecolor = tileNext.Tilecolor;
        // colorSprite.setTexture(tiles[y][x].Tilecolor);
        // tileNext.Tilecolor = textures[1];
        // colorSprite.setTexture(tileNext.Tilecolor);
        tiles[y][x].tileDetails.BorderTop = tileNext.tileDetails.BorderTop;
        tiles[y][x].tileDetails.BorderBot = tileNext.tileDetails.BorderBot;
        tiles[y][x].tileDetails.BorderLeft = tileNext.tileDetails.BorderLeft;
        tiles[y][x].tileDetails.BorderRight = tileNext.tileDetails.BorderRight;
        tileNext.tileDetails.BorderTop = tilesDetails[1].BorderTop;
        tileNext.tileDetails.BorderBot = tilesDetails[1].BorderBot;
        tileNext.tileDetails.BorderLeft = tilesDetails[1].BorderLeft;
        tileNext.tileDetails.BorderRight = tilesDetails[1].BorderRight;
        // tileNext.tileDetails.texture = textures[1];
        tileNext.index = 1;
        // int **a = Board2Matrix();
        //  print check path for all x and y = 0

        return true;

    } else {
        // Tile is not empty, do not place the tile
        std::cout << "Cannot place a tile on a non-empty tile." << std::endl;
        return false;
    }
}

int **TileToMatrix(TraxTuile tile) {
    // For example for an empty tile it will return a 2D array of
    // {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}}
    // For a tile with index 1 it will return a 2D array of
    // {{-1,1,-1},{2,0,2},{-1,1,-1}} For a tile with index 2 it will return
    // a 2D array of {{-1,2,-1},{1,0,1},{-1,2,-1}} For a tile with index 3
    // it will return a 2D array of {{-1,1,-1},{1,0,2},{-1,2,-1}} For a tile
    // with index 4 it will return a 2D array of
    // {{-1,1,-1},{2,0,1},{-1,2,-1}} For a tile with index 5 it will return
    // a 2D array of {{-1,2,-1},{2,0,1},{-1,1,-1}} For a tile with index 6
    // it will return a 2D array of {{-1,2,-1},{1,0,2},{-1,1,-1}}
    int **matrix = new int *[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new int[3];
    }
    // initialize the matrix to 3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 9;
        }
    }
    // initialize the matrix to the correct values

    // if tile not empty add at the center of the matrix the value 0

    if (tile.state != TileState::Empty) {
        matrix[0][1] = tile.tileDetails.BorderTop;
        matrix[1][0] = tile.tileDetails.BorderLeft;
        matrix[1][2] = tile.tileDetails.BorderRight;
        matrix[2][1] = tile.tileDetails.BorderBot;
        matrix[1][1] = 3;
    }
    // Print the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return matrix;
}

int **traxGrid::Board2Matrix() {
    // Create a 2D array of int that will contain the whole board
    int **matrix = new int *[BOARD_HEIGHT * 3];
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        matrix[i] = new int[BOARD_WIDTH * 3];
    }
    // initialize the matrix to -1
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        for (int j = 0; j < BOARD_WIDTH * 3; j++) {
            matrix[i][j] = 9;
        }
    }
    // initialize the matrix to the correct values
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            int **tileMatrix = TileToMatrix(tiles[y][x]);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matrix[y * 3 + i][x * 3 + j] = tileMatrix[i][j];
                }
            }
        }
    }
    // Print the matrix
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        for (int j = 0; j < BOARD_WIDTH * 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return matrix;
}