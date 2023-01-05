all : main.o tuile.o grid.o
	g++ tuile.o grid.o main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp hpp/tuile.hpp
	g++ -c main.cpp

tuile.o : tuile.cpp hpp/tuile.hpp
	g++ -c tuile.cpp

grid.o : grid.cpp hpp/grid.hpp
	g++ -c grid.cpp

clean:
	rm -rf *.o main
