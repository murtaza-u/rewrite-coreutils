#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

#define PRINT_ALL 31
#define PRINT_KERNEL 1
#define PRINT_NODENAME 2
#define PRINT_RELEASE 4
#define PRINT_VERSION 8
#define PRINT_MACHINE 16

int main (int argc, char *argv[]) {
    char ch;
    int print_mask = 0;

    while ((ch = getopt(argc, argv, "asnrvm")) != -1) {
        switch (ch) {
            case 'a':
                print_mask |= PRINT_ALL;
                break;

            case 's':
                print_mask |= PRINT_KERNEL;
                break;

            case 'n':
                print_mask |= PRINT_NODENAME;
                break;

            case 'r':
                print_mask |= PRINT_RELEASE;
                break;

            case 'v':
                print_mask |= PRINT_VERSION;
                break;

            case 'm':
                print_mask |= PRINT_MACHINE;
                break;

            default:
                return 1;
        }
    }

    if (optind != argc) return 1;
    if (!print_mask) print_mask |= PRINT_KERNEL;

    struct utsname u;
    if (uname(&u) == -1) {
        fprintf(stdout, "uname failed");
        return 1;
    }

    int space = 0;

    if (print_mask & PRINT_KERNEL) {
        printf("%s", u.sysname);
        space ++;
    }

    if (print_mask & PRINT_NODENAME) {
        if (space ++) putchar(' ');
        printf("%s", u.nodename);
    }

    if (print_mask & PRINT_RELEASE) {
        if (space ++) putchar(' ');
        printf("%s", u.release);
    }

    if (print_mask & PRINT_MACHINE) {
        if (space ++) putchar(' ');
        printf("%s", u.machine);
    }

    if (print_mask & PRINT_VERSION) {
        if (space ++) putchar(' ');
        printf("%s", u.version);
    }

    putchar('\n');

    return 0;
}
