#include <SDL2/SDL.h>
#include "gui.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

static SDL_Window* window;
static SDL_Renderer* renderer;

void freeGui();
void renderRectangle(int x, int y, int w, int h, RGBA rgba);

int initializeWindow() {
    //Check if SDL2 can be initialized
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "could not initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }

    //Setting up the window
    window = SDL_CreateWindow("Switcheroo",
			    0, 0,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    //If shit's trashed
    if (window == NULL) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    return 0;
}

void delay(int time) {
    SDL_Delay(time);
}


void freeGui() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

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
}