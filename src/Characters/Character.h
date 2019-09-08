#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Terrain/Square.h"
#include "../Terrain/Level.h"

class Character {
    Level* currentLevel;
    Square* currentSquare;

    public:
        Character(Level*);
        void place(int row, int col) {
            Square* square = currentLevel->getSquare(row, col);
            square->occupied = true;
            if(currentSquare != NULL)
                currentSquare->occupied = false;
            currentSquare = square;
        }
};

Character::Character(Level* level){
    currentLevel = level;
}

#endif