#include "window.hpp"
#include "assert.hpp"

Window Window::create(const std::string& title, int width, int height) {
    SDL_Window *w = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED_DISPLAY(0),
            SDL_WINDOWPOS_CENTERED_DISPLAY(0),
            width,
            height,
            0);
    ASSERT(w != NULL, "SDL failed to create window: %s\n", SDL_GetError());
    return Window{w};
}

Window::Window(SDL_Window* w) : window(w) {}

Window::~Window() {
    SDL_DestroyWindow(const_cast<SDL_Window *>(window));
}
