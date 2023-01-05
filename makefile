all : main.o tuile.o grid.o traxTuile.o traxGrid.o
	g++ tuile.o grid.o main.o traxTuile.o traxGrid.o -o main -lsfml-graphics -lsfml-window -lsfml-system

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

clean:
	rm -rf *.o main
