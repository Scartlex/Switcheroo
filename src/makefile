SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp) #Includes all the source files from the root directory as well as all subdirectories (but it does not go deeper than 1 level)
OBJECTS = $(SOURCES:.cpp=.o) #All the object files associated with the source files
FLAGS   = -lSDL2 #All necessary flags

all: $(OBJECTS)
	g++ $(OBJECTS) $(FLAGS) -o main

gui.o: GUI/gui.h
	g++ gui.cpp -c -o gui.o

Square.o: Terrain/Square.h
	g++ Square.cpp -c -o Square.o

main.o: main.h GUI/gui.h
	g++ main.cpp -c -o main.o