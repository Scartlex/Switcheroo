#ifndef GUI_H_
#define GUI_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 600

#define RECT_HEIGHT 50
#define RECT_WIDTH 50

struct RGBA {
    int r;
    int g;
    int b;
    int a;
};

int initializeWindow();

void renderSquare(int x, int y, RGBA rgba);

#endif