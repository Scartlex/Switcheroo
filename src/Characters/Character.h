#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Terrain/Square.h"
#include "../Terrain/Level.h"
#include "../GUI/gui.h"
#include <unistd.h>

class Character {
    public:
        Level* currentLevel;
        Square* currentSquare;
        Square* previousSquare;
        Character(Level*);
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
                place(currentSquare->x + x, currentSquare->y + y);
            else
                place(0, 0);
        }
        void moveAnimation() {
            printf("%d, %d\n", currentSquare==NULL, previousSquare==NULL);
            if(currentSquare != NULL && previousSquare != NULL){
                int oldX = previousSquare->x*50;
                int oldY = previousSquare->y*50;
                int newX = currentSquare->x*50;
                int newY = currentSquare->y*50;

                printf("%d, %d, %d, %d\n", oldX, oldY, newX, newY);

                while(oldX != newX || oldY != newY){
                    if(oldX < newX) oldX += 5; else if(oldX > newX) oldX -= 5;
                    if(oldY < newY) oldY += 5; else if(oldY > newY) oldY -= 5;

                    currentLevel->render();
                    renderRectangle(oldX, oldY, 50, 50, {255, 0, 0, 255}, true);
                    commit();
                    usleep(10000);
                }
            }
        }
        void render() {
            if(currentSquare != NULL)
                renderRectangle(currentSquare->x*50, currentSquare->y*50, 50, 50, {255, 0, 0, 255}, true);
        }
};

Character::Character(Level* level){
    currentLevel = level;
}

#endif