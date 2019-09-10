#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Terrain/Square.h"
#include "../Terrain/Level.h"

class Character {
    public:
        Level* currentLevel;
        Square* currentSquare;
        Character(Level*);
        void place(int row, int col) {
            Square* square = currentLevel->getSquare(row, col);
            if(square != NULL) {
                square->occupied = true;
                if(currentSquare != NULL)
                    currentSquare->occupied = false;
                currentSquare = square;
            }
        }
        void move(int x, int y) {
            if(currentSquare != NULL)
                place(currentSquare->x + x, currentSquare->y + y);
            else
                place(0, 0);
        }
};

Character::Character(Level* level){
    currentLevel = level;
}

#endif