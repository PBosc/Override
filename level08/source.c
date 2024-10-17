#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void log_wrapper(FILE *file, char *prefix, char *format)
{
    size_t end;
    char log[264];

    strcpy(log, prefix);
    size_t len = strlen(log);
    snprintf(log + len, 254 - len, format);
    end = strcspn(log, "\n");
    log[end] = '\0';
    fprintf(file, "LOG: %s\n", log);
    return;
}

int main(int argc, char **argv)
{
    int fd;
    FILE *logfile;
    FILE *stream;
    char path[104];

    if (argc != 2)
        printf("Usage: %s filename\n", argv[0]);
    logfile = fopen("./backups/.log", "w");
    if (logfile == NULL)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }
    log_wrapper(logfile, "Starting back up: ", argv[1]);
    stream = fopen(argv[1], "r");
    if (stream == NULL)
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }
    strncpy(path, "./backups/", 11);
    strncat(path, argv[1], 99 - strlen(path));
    fd = open(path, 193, 432);
    if (fd < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }
    char c = -1;
    while (true)
    {
        c = (char)fgetc(stream);
        if (c == -1)
            break;
        write(fd, &c, 1);
    }
    log_wrapper(logfile, "Finished back up ", argv[1]);
    fclose(stream);
    close(fd);
    return 0;
}
