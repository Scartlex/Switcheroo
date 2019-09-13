#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "gui.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void freeGui();
void renderRectangle(int x, int y, int w, int h, RGBA rgba);

SDL_Window* window;
SDL_Surface* windowSurface;
SDL_Renderer* renderer;

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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) printf("Renderer could not be created: %s\n", SDL_GetError());
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    windowSurface = SDL_GetWindowSurface(window);
    if( window == NULL ){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    if(!IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) {
        printf("SDL image could not initialize! %s\n", IMG_GetError());
        return 1;
    }
    
    return 0;
}

SDL_Texture* loadTexture(std::string path) {
    SDL_Texture* texture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL) printf("Unable to load the image: %s\n", IMG_GetError());
    else {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(texture == NULL) printf("Unable to create texture: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(loadedSurface);
    return texture;
}

void freeGui() {
    SDL_FreeSurface(windowSurface);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}