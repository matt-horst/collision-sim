#pragma once

#include "smath.hpp"
#include "screen.hpp"


class Particle {
public:
    Particle(vec2<f32> position, vec2<f32> velocity, u32 radius, u32 color);
    void draw(Screen &screen);

private:
    vec2<f32> position;
    vec2<f32> velocity;
    const u32 radius;
    const u32 color;
};
