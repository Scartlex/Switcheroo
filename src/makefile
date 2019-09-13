SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp) #Includes all the source files from the root directory as well as all subdirectories (but it does not go deeper than 1 level)
OBJECTS = $(SOURCES:.cpp=.o) #All the object files associated with the source files
FLAGS   = -lSDL2 -lSDL2_image -std=c++11 -pthread #All necessary flags

all: $(OBJECTS)
	g++ $(OBJECTS) $(FLAGS) -o main

gui.o: GUI/gui.cpp GUI/gui.h
	g++ gui.cpp -c -o gui.o

Square.o: Terrain/Square.cpp Terrain/Square.h GUI/gui.h
	g++ Square.cpp -c -o Square.o

Level.o: Terrain/Level.cpp Terrain/Level.h GUI/gui.h
	g++ Level.cpp -c -o Level.o

Character.o: Characters/Character.cpp Characters/Character.h Terrain/Level.h Terrain/Square.h
	g++ Character.cpp -c -o Character.o

keyListener.o: Controls/keyListener.cpp Controls/keyListener.h
	g++ keyListener.cpp -c -o keyListener.o

main.o: main.cpp main.h GUI/gui.h Terrain/Square.h Controls/keyListener.h Characters/Character.h
	g++ main.cpp -c -o main.o

Timer.o: Timer.cpp Timer.h
	g++ Timer.cpp -c -o Timer.o

.PHONY:clean
clean:
	find . -name "*.o" | xargs rm -vf
	rm -vf main