#include <SDL2/SDL_events.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include "assert.hpp"
#include "screen.hpp"
#include "simulator.hpp"


int main() {
    ASSERT(SDL_Init(SDL_INIT_VIDEO) == 0, "SDL failed to initialize: %s\n", SDL_GetError());

    Screen screen = {"Collision Sim", 800, 800};

    Simulator sim = {32, screen.width - 100, screen.height - 100};

    sim.render(screen);
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                    screen.clear();
                } if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
                    sim.render(screen);
                }
            }
        }

        screen.draw();
    }

    return EXIT_SUCCESS;
}
