#include <SDL2/SDL.h>
#include "gui.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void freeGui();
void renderRectangle(int x, int y, int w, int h, RGBA rgba);

SDL_Window* window;
SDL_Surface* windowSurface;

int initializeWindow() {

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    //Setting up the window
    window = SDL_CreateWindow("Switcheroo",
			    0, 0,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    windowSurface = SDL_GetWindowSurface(window);

    if( window == NULL ){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return 1;
    }

    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderClear(renderer);
    return 0;
}

void delay(int time) {
    SDL_Delay(time);
}


void freeGui() {
    SDL_FreeSurface(windowSurface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
/* 
void renderRectangle(int x, int y, int w, int h, RGBA rgba, bool fill) {
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor( renderer, rgba.r, rgba.g, rgba.b, rgba.a );
    if(fill)
        SDL_RenderFillRect(renderer, &rect);
    else
        SDL_RenderDrawRect(renderer, &rect);
}

void commit() {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
} */