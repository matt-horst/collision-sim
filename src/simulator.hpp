#pragma once

#include <cstdint>
#include <vector>
#include "particle.hpp"
#include "screen.hpp"

class Simulator {
public:
    void step();
    void run();
    void render(Screen &screen);
    Simulator(size_t count, uint32_t width, uint32_t height);

    const uint32_t count;
    const uint32_t width;
    const uint32_t height;

private:
    std::vector<Particle> particles;
};
