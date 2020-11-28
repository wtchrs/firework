#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <numbers>

template <int NUM_BRANCH>
class firework
{
public:
    using DIRECTIONS = std::array<double, NUM_BRANCH>;

private:
    int const termwidth, termheight;
    int const center, height;
    int const speed;
    int       current_height = 0;

    double const radius;
    double       current_radius = 0;

    DIRECTIONS directions;

    bool launch_finished = false, pop_finished = false;

public:
    firework(int twidth, int theight, int speed)
        : termwidth(twidth),
          termheight(theight),
          center(twidth / 2),
          height(termheight * 2 / 3),
          radius(std::min(twidth, theight - height) * 2.0 / 5.0),
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

    void draw_floor() const;
    void draw_launch();
    void draw_pop();
    bool draw_update();
};

void gotoxy(int, int);
