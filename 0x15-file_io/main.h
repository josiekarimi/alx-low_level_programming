#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void error_exit(const char *msg, int code);
void cp_file(const char *file_from, const char *file);
void display_error(const char *message);
void read_elf_header(const char *filename);

#endif /* MAIN_H */
