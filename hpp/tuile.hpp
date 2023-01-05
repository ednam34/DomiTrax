#ifndef TUILE_HPP
#define TUILE_HPP

#include <iostream>
#include <string>
#include <vector>

enum class TileState { Empty, Player1, Player2 };

class Tuile {
   public:
    Tuile();
    Tuile(int x, int y,int orientation);
    virtual ~Tuile();
    void setX(int x);
    void setY(int y);
    void setOrientation(int orientation);
    void setState(TileState state);
    int getX();
    int getY();
    int getOrientation();
   
   protected:
    int x, y;
    int orientation;
    TileState state;

};


#endif  // TUILE_HPP