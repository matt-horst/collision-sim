#include "particle.hpp"

Particle::Particle(vec2<f32> position, vec2<f32> velocity, u32 radius, u32 color)
    : position(position), velocity(velocity), radius(radius), color(color) {}

/*
 * Draws the particle as a circle using the Midpoint Circle Algorithm
 * https://en.wikipedia.org/w/index.php?title=Midpoint_circle_algorithm&oldid=889172082#C_example
 * */
void Particle::draw(Screen &screen) {
    int x0 = position.x;
    int y0 = position.y;
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        screen.set_pixel(x0 + x, y0 + y, color);
        screen.set_pixel(x0 + y, y0 + x, color);
        screen.set_pixel(x0 - y, y0 + x, color);
        screen.set_pixel(x0 - x, y0 + y, color);
        screen.set_pixel(x0 - x, y0 - y, color);
        screen.set_pixel(x0 - y, y0 - x, color);
        screen.set_pixel(x0 + y, y0 - x, color);
        screen.set_pixel(x0 + x, y0 - y, color);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}
