#include <firework.hpp>

void gotoxy(int x, int y) {
    printf("\033[%d;%df", y + 1, x + 1);
    fflush(stdout);
}

void draw_floor(int width, int height) {
    for (int i = 0; i < width; ++i) {
        gotoxy(i, height);
        fputs("─", stdout);
    }
}

template <int NUM_BRANCH>
bool firework<NUM_BRANCH>::draw_update() {
    if (!this->launch_finished) {
        this->draw_launch();
    } else if (!this->pop_finished) {
        this->draw_pop();
    }
    return this->pop_finished;
}

template <int NUM_BRANCH>
void firework<NUM_BRANCH>::draw_launch() {
    if (!this->launch_finished) {
        if (this->current_height + 1 <= this->height) {
            gotoxy(this->center, this->bottom - this->current_height - 1);
            fputs("|", stdout);
            ++(this->current_height);
        } else
            this->launch_finished = true;
    }
}

template <int NUM_BRANCH>
void firework<NUM_BRANCH>::draw_pop() {
    if (!this->pop_finished) {
        if (this->current_radius <= this->radius) {
            for (double direction : this->directions) {
                int x = this->center
                        - (this->current_radius * std::sin(direction) * 2);
                int y = this->bottom
                        - (this->height
                           + this->current_radius * std::cos(direction));
                gotoxy(x, y);
                fputc('*', stdout);
            }
            this->current_radius += 1;
        } else
            this->pop_finished = true;
    }
}

template class firework<7>;
