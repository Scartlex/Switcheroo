#include <SDL2/SDL.h>
#include <stdio.h>
#include <thread>
#include "GUI/gui.h"
#include "Terrain/Level.h"
#include "Characters/Character.h"
#include "Controls/keyListener.h"

static Level level(10, 10);
static Character character(&level);

void render() {
    character.moveAnimation();
}

void onKey(int key) {
    switch(key){
        case NORTHWEST:
            character.move(-1, -1);
            break;
        case SOUTHWEST:
            character.move(-1, 1);
            break;
        case SOUTHEAST:
            character.move(1, 1);
            break;
        case NORTHEAST:
            character.move(1, -1);
            break;
        case NORTH:
            character.move(0, -1);
            break;
        case WEST:
            character.move(-1, 0);
            break;
        case SOUTH:
            character.move(0, 1);
            break;
        case EAST:
            character.move(1, 0);
            break;
    }
    render();
}

int main(int argc, char* args[]) {
    initializeWindow();
    character.place(5, 5);
    std::thread t1(keyListener, &onKey);
    level.render();
    character.render();
    commit();
    t1.join();
    freeGui();
    return EXIT_SUCCESS;
}