#include <sys/ioctl.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>
#include <firework.hpp>

int main() {
    system("clear");

    winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    firework<7> fw(ws.ws_col, ws.ws_row, 4);

    fw.draw_floor();

    while (!fw.draw_update()) {
        sleep(1);
    }

    gotoxy(ws.ws_row, ws.ws_col);
    printf("\n");
}
