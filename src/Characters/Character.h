#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Terrain/Square.h"
#include "../Terrain/Level.h"
#include "../GUI/gui.h"
#include "../Controls/keyListener.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Character {
    public:
        Level* currentLevel;
        Square* currentSquare;
        Square* previousSquare;
        Character() : currentLevel(NULL) {}
        Character(Level*);
        ~Character(void);
        void place(int row, int col) {
            Square* square = currentLevel->getSquare(row, col);
            if(square != NULL) {
                square->occupied = true;
                if(currentSquare != NULL)
                    currentSquare->occupied = false;
                previousSquare = currentSquare;
                currentSquare = square;
            } else previousSquare = currentSquare;
        }
        void move(int x, int y) {
            if(currentSquare != NULL)
                place(currentSquare->row + x, currentSquare->col + y);
            else
                place(0, 0);
        }
        void moveAnimation(string sprite, int spriteRenderCycle, Directions direction, int pixelOffset) {
            int y=previousSquare->rect.y, x=previousSquare->rect.x;
            switch(direction) {
                case NORTH: y=previousSquare->rect.y-pixelOffset;break;
                case EAST:  x=previousSquare->rect.x+pixelOffset;break;
                case SOUTH: y=previousSquare->rect.y+pixelOffset;break;
                case WEST:  x=previousSquare->rect.x-pixelOffset;break;
            }
            std::cout << "\tpreviousX: " << previousSquare->rect.x << ", previousY: " << previousSquare->rect.y << "\n";
            std::cout << "\tPlacing character @ x: " << x << ", y: " << y << "\n";

            SDL_Rect rect;
            rect.x = x;
            rect.y = y;
            rect.w = previousSquare->rect.w;
            rect.h = previousSquare->rect.h;

            render(&rect, sprite + std::to_string(spriteRenderCycle));
        }
        void render(SDL_Rect* rect, string sprite) {
            if(currentSquare != NULL) {
                if(sprite == "")
                    texture = loadTexture("GUI/res/sprites/character/front/1.bmp");
                else texture = loadTexture(("GUI/res/sprites/character/" + sprite + ".bmp").c_str());

                if(rect == NULL)
                    SDL_RenderCopy(renderer, texture, NULL, &currentSquare->rect);
                else SDL_RenderCopy(renderer, texture, NULL, rect);
            }
        }
    private:
        SDL_Texture* texture;
};

Character::Character(Level* level){
    currentLevel = level;
}

Character::~Character() {
    
}

#endif