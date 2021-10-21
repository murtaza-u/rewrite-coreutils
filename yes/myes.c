#include <stdio.h>

int main (int argc, char *argv[]) {
    if (argc == 1)
        for (;;) puts("y");
    else
        for (;;) puts(argv[1]);
    return 0;
}
