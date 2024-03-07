#include "simulator.hpp"
#include "particle.hpp"
#include "assert.hpp"
#include <cstddef>
#include <cstdint>
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>
#include <stdio.h>

Simulator::Simulator(size_t count, uint32_t width, uint32_t height)
    : count(count), width(width), height(height), particles({})
{
    // Color Format: ABGR
    u32 colors[] = {0xFFFF0000, 0xFF00FF00, 0xFF0000FF, 0xFFFFFF00, 0xFF00FFFF};
    size_t num_colors = sizeof(colors) / sizeof(u32);

    constexpr u32 min_radius = 10;
    constexpr u32 max_radius = 40;
    constexpr f32 max_speed = 10;

    const u32 seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::random_device r;
    std::default_random_engine eng(r());
    std::uniform_int_distribution<u32> dist_u32(min_radius, max_radius >> 1);
    std::uniform_real_distribution<f32> dist_f32;
    
    u32 row_count = height / (2*max_radius);
    u32 col_count = width / (2*max_radius);
    
    ASSERT(row_count * col_count >= count, "Too many particles requested.\n");

    std::vector<vec2<f32>> cells = {};
    for (size_t i=0; i<row_count; i++) {
        for (size_t j=0; j<col_count; j++) {
            cells.push_back({static_cast<f32>(2*i*max_radius), static_cast<f32>(2*j*max_radius)});
        }
    }

    std::shuffle(cells.begin(), cells.end(), std::default_random_engine(seed));
    size_t i = 0;
    for (const auto &cell : cells) {
        u32 rad = dist_u32(eng);
        f32 offset_x = dist_f32(eng) * 2 * (max_radius - rad);
        f32 offset_y = dist_f32(eng) * 2 * (max_radius - rad);
        vec2<f32> pos = {cell.x + rad + offset_x, cell.y + rad + offset_y};
        vec2<f32> vel = {dist_f32(eng) * max_speed, dist_f32(eng) * max_speed};
        particles.push_back({pos, vel, rad, colors[i % num_colors]});

        if (++i >= count) break;
    }
}

void Simulator::run() {}

void Simulator::step() {}

void Simulator::render(Screen &screen) {
    for (const auto &p : particles) {
        p.draw(screen);
    }
}
