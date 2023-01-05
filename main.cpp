#include "hpp/grid.hpp"
#include "hpp/traxGrid.hpp"
#include "hpp/tuile.hpp"

int main() {
    Tuile t1(0, 0, 3);

    // create a grid
    Grid g1(10, 10);
    std::cout << g1.getWidth() << std::endl;
    std::cout << g1.getHeight() << std::endl;

    traxGrid tg1 = traxGrid();
    TraxTuile TuileAPlacer = TraxTuile(1, 1, 0);
    TuileAPlacer.tileDetails = {1, 1, 2, 2};
    TuileAPlacer.state = TileState::Player1;
    bool a = tg1.addTraxTuile(TuileAPlacer.getX(), TuileAPlacer.getY(),
                              TuileAPlacer.state);

    bool b = tg1.addTraxTuile(TuileAPlacer.getX(), TuileAPlacer.getY(),
                              TuileAPlacer.state);
    std::cout << b << std::endl;

    tg1.Board2Matrix();
    // TileToMatrix(TuileAPlacer);
    //  tg1.Board2Matrix();
    //   add a tuile to the grid
    /*g1.addTuile(t1);
    Tuile t2 = g1.getTuile(0, 0);*/
    /*std::cout << t2.getX() << std::endl;
    std::cout << t2.getY() << std::endl;
    std::cout << t2.getOrientation() << std::endl;*/

    return 0;
}