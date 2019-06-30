a.out: deck.o gameController.o main.o
	g++ -std=c++11 main.o deck.o gameController.o
main.o: main.cpp gameController.o
	g++ -std=c++11 -c main.cpp
gameController.o: deck.o gameController.cpp gameController.h
	g++ -c gameController.cpp
deck.o: deck.h deck.cpp
	g++ -c deck.cpp
clean:
	rm *.o a.out
