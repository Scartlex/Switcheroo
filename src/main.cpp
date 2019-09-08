#include <SDL2/SDL.h>
#include <stdio.h>
#include <thread>
#include "GUI/gui.h"
#include "Terrain/Level.h"
#include "Characters/Character.h"
#include "Controls/keyListener.h"

int main(int argc, char* args[]) {
    initializeWindow();
    Level level(10, 10);
    Character character(&level);
    character.place(5, 5);
    std::thread t1(keyListener, &character);
    level.render();
    t1.join();
    freeGui();
    return EXIT_SUCCESS;
}