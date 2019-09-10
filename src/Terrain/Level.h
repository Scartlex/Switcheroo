#ifndef LEVEL_H_
#define LEVEL_H_

#include <vector>
#include "Square.h"
#include "../GUI/gui.h"

using namespace std;

class Level {

    public:
        int rows, cols; //Dimensions
        vector< vector<Square> > terrain; //Main terrain, filled with squares
        Level(int, int); //Constructor will initialize the size of the board
        ~Level();
        void render() {
            for(int row = 0; row < rows; row++){
                for(int col = 0; col < cols; col++){
                    terrain[row][col].render();
                }
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
    terrain.resize(rows, vector<Square>(cols)); //Resize and populate 2D-vector
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