#ifndef SQUARE_H_
#define SQUARE_H_

#include "../GUI/gui.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#define STANDARD_LENGTH 64

class Square {

    public:
        int row;
        int col;
        SDL_Rect rect;
        bool occupied;
        Square() : row(-1), col(-1), occupied(0) {}
        Square(int xPos, int yPos);
        ~Square(void);
        void load(std::string type) {
            texture = loadTexture("GUI/res/sprites/terrain/" + type + ".bmp");
        }
        int render() {
            SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
        void move(int x, int y) {
            place(rect.x+x, rect.y+y);
        }
        void place(int x, int y) {
            rect.x = x;
            rect.y = y;
        }
    private:
        SDL_Texture* texture;
};

Square::Square(int xPos, int yPos) {
    row = xPos;
    col = yPos;
    rect.x = xPos*STANDARD_LENGTH;
    rect.y = yPos*STANDARD_LENGTH;
    rect.w = STANDARD_LENGTH;
    rect.h = STANDARD_LENGTH;
    occupied = false;
}

Square::~Square() {
    
}

#endif