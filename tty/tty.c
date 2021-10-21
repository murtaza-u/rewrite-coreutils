#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main (int argc, char *argv[]) {
    char ch;
    bool sflag = 0;

    while ((ch = getopt(argc, argv, "s")) != -1) {
        switch (ch) {
            case 's':
                sflag = 1;
                break;
            default:
                return 1;
                break;
        }
    }

    char *t = ttyname(STDIN_FILENO);
    if (!sflag) puts(t ? t : "not a tty");

    return t ? 0 : 1;
}
