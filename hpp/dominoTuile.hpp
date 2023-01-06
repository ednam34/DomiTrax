#ifndef DOMINOTUILE_HPP
#define DOMINOTUILE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "tuile.hpp"

struct Borders {
    int a;
    int b;
    int c;
};

class DominoTuile : public Tuile {
   public:
    DominoTuile();
    DominoTuile(int x, int y, int orientation, std::vector<Borders> values);
    ~DominoTuile();
    void setX(int x);
    void setY(int y);
    void setOrientation(int orientation);
    int getX();
    int getY();
    int getOrientation();
    void setValues(std::vector<Borders> values);
    std::vector<Borders> getValues();
    void printBorders();
    bool isBoardEmpty();
    void setIsEmpty(bool isEmpty);

   protected:
    std::vector<Borders> values;
    bool isEmpty = true;
};

#endif