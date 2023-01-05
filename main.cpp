#include "hpp/tuile.hpp"
#include "hpp/grid.hpp"


int main() {
    Tuile t1(0, 0, 3);


    //create a grid
    Grid g1(10, 10);
    std::cout << g1.getWidth() << std::endl;
    std::cout << g1.getHeight() << std::endl;

    //add a tuile to the grid
    g1.addTuile(t1);
    Tuile t2 = g1.getTuile(0, 0);
    std::cout << t2.getX() << std::endl;
    std::cout << t2.getY() << std::endl;
    std::cout << t2.getOrientation() << std::endl;

    return 0;
}