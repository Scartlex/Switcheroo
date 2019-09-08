#include <SDL2/SDL.h>

class Square {
    public:
        bool occupied;
        SDL_Rect render(int upperLeftX, int upperLeftY);

    /* SDL_Rect render(int upperLeftX, int upperLeftY) {
        return SDL_FillRect(upperLeftX, upperLeftY, 10, 10)
    } */
};