#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <err.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

void readout(int fd) {
    struct stat sbuf;
    size_t buf_size;
    char *buf;

    // st_blksize gives the preferred block size for efficient filesystem I/O
    buf_size = MAX(sbuf.st_blksize, BUFSIZ);

    if (!(buf = (char *)malloc(buf_size))) return;
    while (read(fd, buf, buf_size)) fprintf(stdout, "%s", buf);
}

bool exists(char *filepath) {
    if (access(filepath, F_OK) != 0) {
        warn("%s", filepath);
        return 0;
    }
    return 1;
}

int main (int argc, char *argv[]) {
    if (argc == 1) readout(fileno(stdin));
    else {
        for (argv ++; *argv != NULL; argv ++) {
            if (!exists(*argv)) continue;
            int fd = open(*argv, O_RDONLY);
            readout(fd);
            close(fd);
        }
    }
    return 0;
}
