#ifndef LEVEL_H_
#define LEVEL_H_

#include <vector>
#include "Square.h"
#include "../GUI/gui.h"

using namespace std;

class Level {

    int rows, cols; //Dimensions
    vector< vector<Square> > terrain; //Main terrain, filled with squares

    public:
        Level(int, int); //Constructor will initialize the size of the board
        ~Level();
        void render() {
            for(int row = 0; row < rows; row++){
                for(int col = 0; col < cols; col++){
                    terrain[row][col].render();
                }
            }
            commit();
        }
        Square* getSquare(int row, int col) {
            Square* square = &terrain[row][col];
            return square;
        }

};

Level::Level(int r, int c) {
    rows=r;
    cols=c;
    terrain.resize(rows, vector<Square>(cols)); //Resize and populate 2D-vector
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            terrain[row][col] = Square(row*50, col*50);
        }
    }
}

Level::~Level(void) {
    //Nothing to destroy here because there are no pointers involved (?)
}


#endif