#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Terrain/Square.h"
#include "../Terrain/Level.h"
#include "../GUI/gui.h"
#include "../Controls/keyListener.h"
#include <unistd.h>
#include <iostream>
#include <string>

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
        void moveAnimation() {
            if(currentSquare != NULL && previousSquare != NULL){
                int oldX = previousSquare->rect.x;
                int oldY = previousSquare->rect.y;
                int newX = currentSquare->rect.x;
                int newY = currentSquare->rect.y;

                int spriteRenderCycle = 1;
                int renderDelay = 0;
                int direction = NORTH;
                if(oldX < newX) direction = EAST;
                else if(oldX > newX) direction = WEST;
                else if(oldY < newY) direction = SOUTH;
                string sprite = "";
                switch(direction){
                    case NORTH: sprite = "back/";break;
                    case EAST:  sprite = "right/";break;
                    case SOUTH: sprite = "front/";break;
                    case WEST: sprite = "left/";break;
                }
                
                while(oldX != newX || oldY != newY){
                    switch(direction) {
                        case NORTH: oldY-=4;break;
                        case EAST:  oldX+=4;break;
                        case SOUTH: oldY+=4;break;
                        case WEST:  oldX-=4;break;
                    }
                    previousSquare->render();
                    currentSquare->render();
                    SDL_Rect rect;
                    rect.x = oldX;
                    rect.y = oldY;
                    rect.w = previousSquare->rect.w;
                    rect.h = previousSquare->rect.h;

                    if(renderDelay == 5) {
                        printf("Using new sprite to render with \n");
                        if(spriteRenderCycle == 3)spriteRenderCycle = 0; else spriteRenderCycle++;
                        renderDelay = 0;
                    } else renderDelay++;
                    render(&rect, sprite + std::to_string(spriteRenderCycle));

                    usleep(10000);
                }
                render(NULL, sprite + "1");
            }
        }
        void render(SDL_Rect* rect, string sprite) {
            if(currentSquare != NULL) {
                if(sprite == "")
                    surface = SDL_LoadBMP("GUI/res/sprites/character/front/1.bmp");
                else surface = SDL_LoadBMP(("GUI/res/sprites/character/" + sprite + ".bmp").c_str());
                if(rect == NULL)
                    SDL_BlitSurface(surface, NULL, windowSurface, &currentSquare->rect);
                else SDL_BlitSurface(surface, NULL, windowSurface, rect);
                SDL_UpdateWindowSurface(window);
            }
        }
    private:
        SDL_Surface* surface;
};

Character::Character(Level* level){
    currentLevel = level;
}

Character::~Character() {
    SDL_FreeSurface(surface);
}

#endif