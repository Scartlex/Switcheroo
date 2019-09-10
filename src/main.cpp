#include <SDL2/SDL.h>
#include <stdio.h>
#include <thread>
#include "GUI/gui.h"
#include "Terrain/Level.h"
#include "Characters/Character.h"
#include "Controls/keyListener.h"

static Level level(10, 10);
static Character character(&level);

void onKey(int key) {
    switch(key){
        case SDLK_w:
            character.move(0, -1);
            break;
        case SDLK_a:
            character.move(-1, 0);
            break;
        case SDLK_s:
            character.move(0, 1);
            break;
        case SDLK_d:
            character.move(1, 0);
            break;
    }
    level.render();
}

int main(int argc, char* args[]) {
    initializeWindow();
    character.place(5, 5);
    std::thread t1(keyListener, &onKey);
    level.render();
    t1.join();
    freeGui();
    return EXIT_SUCCESS;
}