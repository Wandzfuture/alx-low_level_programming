#ifndef MAIN_H
#define MAIN_H

#define ERROR_EXIT(msg) do { fprintf(stderr, "Error: %s\n", msg); exit(98); } while (0)
#define ERROR_MSG(msg) fprintf(stderr, "Error: %s\n", msg)

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
