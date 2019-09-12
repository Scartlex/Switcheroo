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
        /* else if(keys[SDL_SCANCODE_W] && keys[SDL_SCANCODE_A])
            onKeyEvent(NORTHWEST);
        else if(keys[SDL_SCANCODE_S] && keys[SDL_SCANCODE_A])
            onKeyEvent(SOUTHWEST);
        else if(keys[SDL_SCANCODE_S] && keys[SDL_SCANCODE_D])
            onKeyEvent(SOUTHEAST);
        else if(keys[SDL_SCANCODE_W] && keys[SDL_SCANCODE_D])
            onKeyEvent(NORTHEAST); */
        else if(keys[SDL_SCANCODE_W])
            onKeyEvent(NORTH);
        else if(keys[SDL_SCANCODE_A])
            onKeyEvent(WEST);
        else if(keys[SDL_SCANCODE_S])
            onKeyEvent(SOUTH);
        else if(keys[SDL_SCANCODE_D])
            onKeyEvent(EAST);

        usleep(10000);
    }
}