#ifndef SQUARE_H_
#define SQUARE_H_

#include "../GUI/gui.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Square {

    public:
        int row;
        int col;
        SDL_Rect rect;
        bool occupied;
        Square() : row(-1), col(-1), occupied(0) {}
        Square(int xPos, int yPos);
        ~Square(void);
        int render() {
            SDL_FillRect(surface, NULL, 0x000000);
            surface = SDL_LoadBMP("GUI/res/sprites/terrain/grass.bmp");
            SDL_BlitSurface(surface, NULL, windowSurface, &rect);
        }
    private:
        SDL_Surface* surface;
};

Square::Square(int xPos, int yPos) {
    row = xPos;
    col = yPos;
    rect.x = xPos*64;
    rect.y = yPos*64;
    rect.w = 64;
    rect.h = 64;
    occupied = false;
}

Square::~Square() {
    
}

#endif