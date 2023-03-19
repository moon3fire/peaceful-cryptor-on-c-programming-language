#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

extern int _payload(
    FILE *(*_fopen) (const char *, const char *),
    int (*_fprintf) (FILE *, const char *, ...),
    int (*_fclose) (FILE *)
) {
    char filename[] = "result.txt";
    char mode[] = "w";
    char format[] = "%s";
	char text[] = "this was encrypted message";

    FILE *file = _fopen(filename, mode);
    if (file == NULL) {
        return 1;
    }

    _fprintf(file, format, text);
    _fclose(file);
    return 0;
}
extern void _end(void);

#endif
