#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "smath.hpp"


class Window {
public:
    Window(const std::string& title, uint32_t width, uint32_t height);
    ~Window();
    inline SDL_Window *get();

    const SDL_Window* const window;
    const uint32_t width;
    const uint32_t height;
};


class Renderer {
public:
    Renderer(const Window &window);
    const SDL_Renderer * const renderer;
    ~Renderer();
    inline SDL_Renderer *get();
};


class Texture {
public:
    Texture(const Renderer &renderer, u32 width, u32 height);
    const SDL_Texture * const texture;
    ~Texture();
    inline SDL_Texture *get();
};


class Screen {
public:
    Screen(const std::string &title, u32 width, u32 height);
    const u32 width;
    const u32 height;
    u32 * const pixels;
    void draw();
    void clear();
    void set_pixel(size_t x, size_t y, u32 color);

private:
    Window window;
    Renderer renderer;
    Texture texture;
    size_t pixels_size;
};
