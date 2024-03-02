#pragma once

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    static Window create(const std::string& title, int width, int height);
    ~Window();

private:
    const SDL_Window* const window;
    Window(SDL_Window* w);
};
