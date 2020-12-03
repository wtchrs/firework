#include <sys/ioctl.h>
#include <unistd.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <firework.hpp>

int main() {
    system("clear");

    winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    // firework<7> fw(ws.ws_col / 2, ws.ws_row, 8);
    firework<7> fw(ws.ws_col / 2, ws.ws_row, ws.ws_row * 3 / 5,
                   std::min(ws.ws_col / 2.0, ws.ws_row * 2 / 5.0) / 2.0, 16);

    draw_floor(ws.ws_col, ws.ws_row);

    while (!fw.draw_update()) {
        usleep(1000000 / fw.get_speed());
    }

    gotoxy(ws.ws_row, ws.ws_col);
    printf("\n");
}
