#ifndef DOMINOTUILE_HPP
#define DOMINOTUILE_HPP

#include "tuile.hpp"
#include <iostream>
#include <string>
#include <vector>

struct Borders {
    int a;  
    int b;
    int c;
};


class DominoTuile: public Tuile {
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


    protected:
        std::vector<Borders> values;
        bool isEmpty = true;
};



#endif // DOMINO_TUILE_HPP