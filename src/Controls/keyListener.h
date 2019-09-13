#ifndef KEYLISTENER_H_
#define KEYLISTENER_H_

enum Directions {
    NORTH,
    WEST,
    SOUTH,
    EAST
};

void keyListener(void(*onKeyEvent)(Directions));

#endif