#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main (int argc, char *argv[]) {
    const char *pwd = NULL;

    if (*++argv && strcmp(*argv, "-P") == 0) pwd = getcwd(NULL, 0);
    else pwd = getenv("PWD");

    if (pwd != NULL) {
        fputs(pwd, stdout);
        putchar('\n');
    }

    return 0;
}
