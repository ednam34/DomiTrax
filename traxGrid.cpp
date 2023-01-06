#include "hpp/traxGrid.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

using namespace std;

traxGrid::traxGrid() : Grid(500, 700) {
    width = BOARD_WIDTH;
    height = BOARD_HEIGHT;
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
}

void traxGrid::updateTileNext() {
    tileNext.setNextTilesDetails(tileNext);
    tileNext.state = TileState::Player1;
    tileNext.tileDetails = tilesDetails[tileNext.index];
    tileNext.setOrientation(0);
}

bool traxGrid::isBoardEmpty() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
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
    if ((x > 0 && tiles[y][x - 1].state != TileState::Empty &&
         tileNext.tileDetails.BorderLeft ==
             tiles[y][x - 1].tileDetails.BorderRight) ||
        (x > 0 && tiles[y][x - 1].state == TileState::Empty) || (x == 0)) {
        if (tiles[y][x - 1].state != TileState::Empty && x != 0) {
            NextTo++;
        }
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
        adjacentTiles++;
    }
    if ((y > 0 && tiles[y - 1][x].state != TileState::Empty &&
         tileNext.tileDetails.BorderTop ==
             tiles[y - 1][x].tileDetails.BorderBot) ||
        (y > 0 && tiles[y - 1][x].state == TileState::Empty) || (y == 0)) {
        if (tiles[y - 1][x].state != TileState::Empty && y != 0) {
            NextTo++;
        }
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
    if (tiles[y][x].state == TileState::Empty) {
        tiles[y][x].state = player;

        tiles[y][x].tileDetails = tileNext.tileDetails;
        tiles[y][x].tileDetails.BorderTop = tileNext.tileDetails.BorderTop;
        tiles[y][x].tileDetails.BorderBot = tileNext.tileDetails.BorderBot;
        tiles[y][x].tileDetails.BorderLeft = tileNext.tileDetails.BorderLeft;
        tiles[y][x].tileDetails.BorderRight = tileNext.tileDetails.BorderRight;
        tiles[y][x].index = tileNext.index;
        tileNext.tileDetails.BorderTop = tilesDetails[1].BorderTop;
        tileNext.tileDetails.BorderBot = tilesDetails[1].BorderBot;
        tileNext.tileDetails.BorderLeft = tilesDetails[1].BorderLeft;
        tileNext.tileDetails.BorderRight = tilesDetails[1].BorderRight;
        if (player == TileState::Player1) {
            tileNext.state = TileState::Player2;
        } else {
            tileNext.state = TileState::Player1;
        }
        tileNext.index = 1;
        int **matrix = Board2Matrix();
        // getFirstMatrix(matrix);
        return true;

    } else {
        std::cout << "Cannot place a tile on a non-empty tile." << std::endl;
        return false;
    }
}

int **TileToMatrix(TraxTuile tile) {
    int **matrix = new int *[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new int[3];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 9;
        }
    }

    if (tile.state != TileState::Empty) {
        matrix[0][1] = tile.tileDetails.BorderTop;
        matrix[1][0] = tile.tileDetails.BorderLeft;
        matrix[1][2] = tile.tileDetails.BorderRight;
        matrix[2][1] = tile.tileDetails.BorderBot;
        matrix[1][1] = 3;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // std::cout << matrix[i][j] << " ";
        }
        // std::cout << std::endl;
    }

    return matrix;
}

int **traxGrid::Board2Matrix() {
    int **matrix = new int *[BOARD_HEIGHT * 3];
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        matrix[i] = new int[BOARD_WIDTH * 3];
    }
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        for (int j = 0; j < BOARD_WIDTH * 3; j++) {
            matrix[i][j] = 9;
        }
    }
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
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        for (int j = 0; j < BOARD_WIDTH * 3; j++) {
            // std::cout << matrix[i][j] << " ";
        }
        // std::cout << std::endl;
    }
    return matrix;
}

/*int **traxGrid::getFirstMatrix(int **matrix) {
    int **firstMatrix = new int *[BOARD_HEIGHT * 3];
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        firstMatrix[i] = new int[BOARD_WIDTH * 3];
    }
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        for (int j = 0; j < BOARD_WIDTH * 3; j++) {
            if (matrix[i][j] == 3 || matrix[i][j] == 2) {
                firstMatrix[i][j] = 0;
            } else {
                firstMatrix[i][j] == 9;
            }
        }
    }
    return firstMatrix;
}*/

/*int **traxGrid::getSecondMatrix(int **matrix) {
    int **secondMatrix = new int *[BOARD_HEIGHT * 3];
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        secondMatrix[i] = new int[BOARD_WIDTH * 3];
    }
    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        for (int j = 0; j < BOARD_WIDTH * 3; j++) {
            if (matrix[i][j] == 3 || matrix[i][j] == 1) {
                secondMatrix[i][j] = 0;
            } else {
                secondMatrix[i][j] == 9;
            }
        }
    }

    for (int i = 0; i < BOARD_HEIGHT * 3; i++) {
        for (int j = 0; j < BOARD_WIDTH * 3; j++) {
            std::cout << secondMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return secondMatrix;
}*/