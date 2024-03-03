#include "screen.hpp"
#include "assert.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>


Window::Window(const std::string &title, uint32_t width, uint32_t height)
    : window(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED_DISPLAY(0),
                       SDL_WINDOWPOS_CENTERED_DISPLAY(0), width, height, 0)),
    width(width), height(height)
{
  ASSERT(window != NULL, "SDL failed to create window: %s\n", SDL_GetError());
}

Window::~Window() { SDL_DestroyWindow(get()); }

SDL_Window * Window::get() { return const_cast<SDL_Window *>(window); }


Renderer::Renderer(const Window &window) 
    : renderer(SDL_CreateRenderer(const_cast<SDL_Window *>(window.window), -1, SDL_RENDERER_PRESENTVSYNC)) 
{
    ASSERT(renderer != NULL, "SDL failed to create renderer: %s\n", SDL_GetError());
}

Renderer::~Renderer() { SDL_DestroyRenderer(get()); }

SDL_Renderer * Renderer::get() { return const_cast<SDL_Renderer *>(renderer); }


Texture::Texture(const Renderer &renderer, u32 width, u32 height)
    : texture(SDL_CreateTexture(
            const_cast<SDL_Renderer *>(renderer.renderer),
            SDL_PIXELFORMAT_ABGR8888, 
            SDL_TEXTUREACCESS_STREAMING,
            width,
            height))
{
    ASSERT(texture != NULL, "SDL failed to create texture: %s\n", SDL_GetError());
}

Texture::~Texture() { SDL_DestroyTexture(get()); }

SDL_Texture * Texture::get() { return const_cast<SDL_Texture *>(texture); }


Screen::Screen(const std::string &title, u32 width, u32 height)
    : width(width), height(height), pixels((u32 *)malloc(width * height * sizeof(u32))),
    window({title, width, height}), renderer({window}), texture({renderer, width, height}),
    pixels_size(width * height * sizeof(u32))
{
    ASSERT(pixels != NULL, "Failed to allocate pixels array.")
}

void Screen::draw() {
    SDL_UpdateTexture(texture.get(), NULL, pixels, width * 4);
    SDL_RenderCopyEx(renderer.get(), texture.get(), NULL, NULL, 0.0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderPresent(renderer.get());
}


void Screen::set_pixel(size_t x, size_t y, u32 color) {
    x += 50;
    y += 50;
    pixels[x * width + y] = color;
}

void Screen::clear() { memset(pixels, 0, pixels_size); }
