#include <SDL2/SDL.h>
#include "gui.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

static SDL_Window* window;
static SDL_Renderer* renderer;

void freeGui();
void renderSquare(int x, int y, RGBA rgba);

int initializeWindow() {
    //Check if SDL2 can be initialized
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "could not initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }

    //Setting up the window
    window = SDL_CreateWindow("Switcheroo",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );

    //If shit's trashed
    if (window == NULL) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    renderSquare(0, 0, {0, 0, 255, 255});

    SDL_Delay(2000);

    freeGui();
    return 0;
}

void freeGui() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void renderSquare(int x, int y, RGBA rgba) {
    SDL_Rect rect = {x, y, 50, 50};
    SDL_SetRenderDrawColor( renderer, rgba.r, rgba.g, rgba.b, rgba.a );
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}