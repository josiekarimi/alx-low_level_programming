#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * error_exit - Prints an error message and exits with the given exit code.
 * @msg: The error message to print.
 * @code: The exit code.
 */
void error_exit(const char *msg, int code)
{
dprintf(STDERR_FILENO, "%s\n", msg);
exit(code);
}

/**
 * cp_file - Copies the content of one file to another file.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 */
void cp_file(const char *file_from, const char *file_to)
{
int fd_from, fd_to, read_count, write_count;
char buf[BUF_SIZE];
fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
error_exit("Error: Can't read from file", 98);
fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
error_exit("Error: Can't write to file", 99);
while ((read_count = read(fd_from, buf, BUF_SIZE)) > 0)
{
write_count = write(fd_to, buf, read_count);
if (write_count == -1 || write_count != read_count)
error_exit("Error: Can't write to file", 99);
}
if (read_count == -1)
error_exit("Error: Can't read from file", 98);
if (close(fd_from) == -1)
error_exit("Error: Can't close fd", 100);
if (close(fd_to) == -1)
error_exit("Error: Can't close fd", 100);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or the corresponding exit code on failure.
 */
int main(int argc, char *argv[])
{
if (argc != 3)
error_exit("Usage: cp file_from file_to", 97);
cp_file(argv[1], argv[2]);
return (0);
}
