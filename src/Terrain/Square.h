#ifndef SQUARE_H_
#define SQUARE_H_

#include "../GUI/gui.h"

class Square {

    public:
        int x;
        int y;
        bool occupied;
        Square() : x(-1), y(-1), occupied(0){}
        Square(int xPos, int yPos) : x(xPos), y(yPos), occupied(0){}
        void render() {
            if(x != -1 && y != -1) {
                if(occupied)
                    renderRectangle(x*50, y*50, 50, 50, {255, 0, 0, 255}, true);
                else
                    renderRectangle(x*50, y*50, 50, 50, {0, 0, 0, 255}, false);
            }
        }
};

#endif