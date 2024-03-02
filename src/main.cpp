#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include "assert.hpp"
#include "window.hpp"


int main() {
    ASSERT(SDL_Init(SDL_INIT_VIDEO) == 0, "SDL failed to initialize: %s\n", SDL_GetError());

    Window window = Window::create("Collision-Sim", 800, 800);

    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    return EXIT_SUCCESS;
}
