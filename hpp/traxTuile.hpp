#ifndef TRAXTUILE_HPP
#define TRAXTUILE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "tuile.hpp"

struct TilesDetails {
    int BorderTop;
    int BorderBot;
    int BorderLeft;
    int BorderRight;
};

class TraxTuile : public Tuile {
   public:
    TraxTuile();
    TraxTuile(int x, int y, int orientation);
    ~TraxTuile();
    void setX(int x);
    void setY(int y);
    void setOrientation(int orientation);
    int getX();
    int getY();
    int getOrientation();
    void setTilesDetails(TilesDetails tilesDetails);
    void setValues(std::vector<int> values);
    std::vector<int> getValues();
    TileState state;
    TilesDetails tileDetails;
    bool isBoardEmpty();
    int index = 0;
    void setNextTilesDetails(TraxTuile tileNext);

   protected:
    std::vector<int> values;
    TilesDetails tilesDetails;
};

#endif  // TRAXTUILE_HPP