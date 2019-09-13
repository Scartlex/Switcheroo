#ifndef LEVEL_H_
#define LEVEL_H_

#include <vector>
#include <SDL2/SDL.h>
#include <time.h>
#include <unistd.h>
#include "Square.h"
#include "../GUI/gui.h"
#include "../Controls/keyListener.h"

using namespace std;

class Level {

    public:
        int rows, cols; //Dimensions
        vector< vector<Square> > terrain; //Main terrain, filled with squares
        Level(int r, int c); //Constructor will initialize the size of the board
        ~Level();
        void render(int xOffset, int yOffset) {
            if(rows != -1 && cols != -1)
                for(int row = 0; row < rows; row++){
                    for(int col = 0; col < cols; col++){
                        terrain[row][col].move(xOffset, yOffset);
                        terrain[row][col].render();
                    }
                }
        }
        void load() {
            srand(time(NULL));
            if(rows != -1 && cols != -1)
                for(int row = 0; row < rows; row++){
                    for(int col = 0; col < cols; col++){
                        double random = ((double) rand() / (RAND_MAX));
                        switch(random < 0.5){
                            case true: terrain[row][col].load("grass");break;
                            case false: terrain[row][col].load("dirt");break;
                        }
                    }
                }
        }
        void scrollAnimation(Directions direction) {
            switch(direction) {
                    case NORTH: render(0, 4);break;
                    case EAST:  render(-4, 0);break;
                    case SOUTH: render(0, -4);break;
                    case WEST:  render(4, 0);break;
                }
        }
        Square* getSquare(int row, int col) {
            if(row >= 0 && row < rows && col >= 0 && col < cols) {
                Square* square = &terrain[row][col];
                return square;
            } else return NULL;
        }
};

Level::Level(int r, int c) {
    rows=r;
    cols=c;
    terrain.resize(r, vector<Square>(c)); //Resize and populate 2D-vector
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            terrain[row][col] = Square(row, col);
        }
    }
}

Level::~Level(void) {
    //Nothing to destroy here because there are no pointers involved (?)
}


#endif