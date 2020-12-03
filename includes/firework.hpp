#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <numbers>

void gotoxy(int, int);
void draw_floor(int, int);

template <int NUM_BRANCH>
class firework
{
public:
    using DIRECTIONS = std::array<double, NUM_BRANCH>;

private:
    int const bottom;
    int const center, height;
    int const speed;
    int       current_height = 1;

    double const radius;
    double       current_radius = 0;

    DIRECTIONS directions;

    bool launch_finished = false, pop_finished = false;

public:
    firework(int center, int bottom, int speed)
        : center(center),
          bottom(bottom),
          height(bottom * 2 / 3),
          radius(std::min(center * 2, bottom - this->height) * 2.0 / 5.0),
          speed(speed) {
        DIRECTIONS init_dir;
        for (int i = 0; i < NUM_BRANCH; ++i) {
            init_dir[i] = 2 * std::numbers::pi * i / NUM_BRANCH;
        }
        this->set_directions(init_dir);
    }

    firework(int center, int bottom, int height, double radius, int speed)
        : center(center),
          bottom(bottom),
          height(height),
          radius(radius),
          speed(speed) {
        DIRECTIONS init_dir;
        for (int i = 0; i < NUM_BRANCH; ++i) {
            init_dir[i] = 2 * std::numbers::pi * i / NUM_BRANCH;
        }
        this->set_directions(init_dir);
    }

    firework() = delete;

    inline void set_directions(DIRECTIONS dir) {
        this->directions = dir;
    }

    inline int get_speed() {
        return this->speed;
    }

    void draw_launch();
    void draw_pop();
    bool draw_update();
};
