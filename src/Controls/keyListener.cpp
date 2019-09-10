#include <SDL2/SDL.h>
#include <unistd.h>
#include "keyListener.h"

void keyListener(void(*onKeyEvent)(int)) {
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    SDL_Event event;
    bool looping = true;

    while(looping) {
        while((SDL_PollEvent(&event)) != 0) {
            if(event.type == SDL_QUIT)
                looping = false;
        }

        if(keys[SDL_SCANCODE_ESCAPE])
            looping = false;
        else if(keys[SDL_SCANCODE_W])
            onKeyEvent(SDLK_w);
        else if(keys[SDL_SCANCODE_A])
            onKeyEvent(SDLK_a);
        else if(keys[SDL_SCANCODE_S])
            onKeyEvent(SDLK_s);
        else if(keys[SDL_SCANCODE_D])
            onKeyEvent(SDLK_d);

        usleep(100000);
    }
}

/* void keyListener(void(*onKeyEvent)(int)) {
    SDL_Event event;
    bool looping = true;
    while(looping) {
        SDL_PollEvent(&event);
        if(event.type == SDL_KEYDOWN)
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    looping = false;
                    break;
                default:
                    onKeyEvent(event.key.keysym.sym);
                    break;
            }
    }
} */