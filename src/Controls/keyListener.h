#ifndef KEYLISTENER_H_
#define KEYLISTENER_H_

enum Directions {
    NORTH,
    WEST,
    SOUTH,
    EAST,

    NORTHWEST,
    SOUTHWEST,
    SOUTHEAST,
    NORTHEAST
};

void keyListener(void(*onKeyEvent)(int));

#endif