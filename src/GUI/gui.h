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

int initializeWindow();
void freeGui();
void delay(int time);
void renderRectangle(int x, int y, int w, int h, RGBA rgba, bool fill);
void commit();

#endif