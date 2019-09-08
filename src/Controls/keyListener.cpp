#include <SDL2/SDL.h>
#include "keyListener.h"
#include "../Characters/Character.h"

void keyListener(Character* character) {
    SDL_Event event;
    bool looping = true;
    while(looping) {
        SDL_PollEvent(&event);
        if(event.type == SDL_KEYDOWN)
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    looping = false;
                    break;
                default: break;
            }
    }
}