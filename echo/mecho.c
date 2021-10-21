#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main (int argc, char *argv[]) {
    bool nflag = 0;

    if (*++argv && strcmp(*argv, "-n") == 0) {
        nflag = 1;
        ++argv;
    }

    while (*argv) {
        fputs(*argv, stdout);
        if (*++argv) putchar(' ');
    }

    if (!nflag) putchar('\n');

    return 0;
}
