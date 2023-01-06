all : main.o tuile.o grid.o traxTuile.o traxGrid.o dominoGrid.o dominoTuile.o traxGridGraphics.o DominoTuileGraphics.o DominoGridGraphics.o
	g++ tuile.o grid.o main.o traxTuile.o traxGrid.o dominoGrid.o dominoTuile.o traxGridGraphics.o DominoTuileGraphics.o DominoGridGraphics.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp hpp/tuile.hpp
	g++ -c main.cpp

tuile.o : tuile.cpp hpp/tuile.hpp
	g++ -c tuile.cpp

grid.o : grid.cpp hpp/grid.hpp
	g++ -c grid.cpp

traxTuile.o : traxTuile.cpp hpp/traxTuile.hpp
	g++ -c traxTuile.cpp

traxGrid.o : traxGrid.cpp hpp/traxGrid.hpp
	g++ -c traxGrid.cpp

dominoGrid.o : dominoGrid.cpp hpp/dominoGrid.hpp
	g++ -c dominoGrid.cpp

dominoTuile.o : dominoTuile.cpp hpp/dominoTuile.hpp
	g++ -c dominoTuile.cpp

traxGridGraphics.o : Graphics/traxGridGraphics.cpp Graphics/hpp/traxGridGraphics.hpp
	g++ -c Graphics/traxGridGraphics.cpp

DominoTuileGraphics.o : Graphics/DominoTuileGraphics.cpp Graphics/hpp/DominoTuileGraphics.hpp
	g++ -c Graphics/DominoTuileGraphics.cpp

DominoGridGraphics.o : Graphics/DominoGridGraphics.cpp Graphics/hpp/DominoGridGraphics.hpp
	g++ -c Graphics/DominoGridGraphics.cpp

clean:
	rm -rf *.o main
