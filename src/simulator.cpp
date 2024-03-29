#include "simulator.hpp"
#include "particle.hpp"
#include <cstddef>
#include <cstdint>
#include <random>

Simulator::Simulator(size_t count, uint32_t width, uint32_t height)
    : count(count), width(width), height(height), particles({})
{
    u32 colors[] = {0xFFFF0000, 0xFF00FF00, 0xFF0000FF, 0xFFFFFF00, 0xFF00FFFF};
    size_t num_colors = sizeof(colors) / sizeof(u32);
    std::random_device r;
    std::default_random_engine eng(r());
    std::uniform_real_distribution<f32> dist;
    for (size_t i = 0; i < count; i++) {
        vec2<f32> pos = {dist(eng)*width, dist(eng)*height};
        vec2<f32> vel = {dist(eng), dist(eng)};
        u32 rad = 24;
        particles.push_back({pos, vel, rad, colors[i % num_colors]});
    }
}

void Simulator::run() {}

void Simulator::step() {}

void Simulator::render(Screen &screen) {
    for (auto p : particles) {
        p.draw(screen);
    }
}
