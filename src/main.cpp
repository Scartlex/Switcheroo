#include <SDL2/SDL.h>
#include <stdio.h>
#include <thread>
#include <sstream>
#include "GUI/gui.h"
#include "Terrain/Level.h"
#include "Terrain/Square.h"
#include "Characters/Character.h"
#include "Controls/keyListener.h"
#include "GUI/Timer.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;

Level level(50, 50);
Character character(&level);

Timer fpsTimer;
Timer capTimer;
int countedFrames = 0;

void onKey(Directions direction) {
    switch(direction){
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
    int pixelsScrolled = 0;
    int spriteRenderCycle = 1;
    int renderDelay = 0;
    string sprite = "";
    switch(direction){
        case NORTH: sprite = "back/";break;
        case EAST:  sprite = "right/";break;
        case SOUTH: sprite = "front/";break;
        case WEST: sprite = "left/";break;
    }
    fpsTimer.start();
    while(pixelsScrolled < STANDARD_LENGTH) {
        capTimer.start();
        pixelsScrolled += 4;
        if(renderDelay == 5) {
            if(spriteRenderCycle == 3) spriteRenderCycle = 1; else spriteRenderCycle++;
            renderDelay = 0;
        } else renderDelay++;
        
        float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
        if(avgFPS > 2000000) avgFPS = 0;
        std::cout << "FPS: " << (int)avgFPS << "\n";
        
        SDL_RenderClear(renderer);
        if(pixelsScrolled <= STANDARD_LENGTH)
            level.scrollAnimation(direction);
        else level.render(0, 0);
        character.moveAnimation(sprite, pixelsScrolled==STANDARD_LENGTH?1:spriteRenderCycle, direction, pixelsScrolled);
        SDL_RenderPresent(renderer);

        ++countedFrames;
        int frameTicks = capTimer.getTicks();
        if(frameTicks < SCREEN_TICKS_PER_FRAME) SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
    }
}

int main(int argc, char* args[]) {
    initializeWindow();
    level.load();
    character.place(5, 5);
    std::thread t1(keyListener, &onKey);
    SDL_RenderClear(renderer);
    level.render(0, 0);
    character.render(NULL, "");
    SDL_RenderPresent(renderer);
    t1.join();
    freeGui();
    return EXIT_SUCCESS;
}