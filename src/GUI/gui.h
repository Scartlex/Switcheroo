#ifndef GUI_H_
#define GUI_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

struct RGBA {
    int r;
    int g;
    int b;
    int a;
};

extern SDL_Window* window;
extern SDL_Surface* windowSurface;

extern SDL_Renderer* renderer;

int initializeWindow();
void freeGui();
SDL_Texture* loadTexture(std::string path);

#endif