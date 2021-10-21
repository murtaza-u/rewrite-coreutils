#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <err.h>

void rm_path(char *path) {
    char *p;

    while ((p = strrchr(path, '/'))) {
        if (rmdir(path) == -1) warn("%s\n", path);
        *p = '\0';
    }

    if (strlen(path) && rmdir(path) == -1)
        warn("%s\n", path);
}

int main (int argc, char *argv[]) {
    char ch;
    bool pflag = 0;

    while ((ch = getopt(argc, argv, "p")) != -1) {
        switch (ch) {
            case 'p':
                pflag = 1;
                break;
            default:
                printf("Invalid flag");
                break;
        }
    }

    argc -= optind;
    argv += optind;

    if (argc == 0) return 1;

    for (; *argv; ++argv) {
        // trim trailing '/'
        char *p = *argv + strlen(*argv);
        while (--p > *argv && *p == '/') continue;
        *++p = '\0';

        if (pflag) rm_path(*argv);
        else if (rmdir(*argv) == -1) warn("%s", *argv);
    }

    return 0;
}
