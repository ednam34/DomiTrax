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
    TraxTuile TuileAPlacerBis = TraxTuile(1, 2, 0);
    TuileAPlacerBis.state = TileState::Player2;

    TuileAPlacerBis.tileDetails = {1, 1, 2, 2};
    bool b = tg1.addTraxTuile(TuileAPlacerBis.getX(), TuileAPlacerBis.getY(),
                              TuileAPlacerBis.state);
    TuileAPlacer.tileDetails = {1, 1, 2, 2};
    std::cout << b << std::endl;

    tg1.Board2Matrix();

    return 0;
}