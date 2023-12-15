#include "shell.h"

/**
 * _eputs - Displays a given string.
 * @str: String to be output.
 * Return: None.
 */
void _eputs(char *str)
{
    int index = 0;

    if (!str)
        return;
    while (str[index] != '\0')
    {
        _eputchar(str[index]);
        index++;
    }
}

/**
 * _eputchar - Outputs a character to the standard error stream.
 * @c: Character to be written.
 * Return: 1 on success, -1 on error with errno set.
 */
int _eputchar(char c)
{
    static int buf_index;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || buf_index >= WRITE_BUF_SIZE)
    {
        write(2, buffer, buf_index);
        buf_index = 0;
    }
    if (c != BUF_FLUSH)
        buffer[buf_index++] = c;
    return (1);
}

/**
 * _putfd - Writes a character to a specified file descriptor.
 * @c: Character to print.
 * @fd: File descriptor for the output.
 * Return: 1 on success, -1 on error with errno set.
 */
int _putfd(char c, int fd)
{
    static int buffer_index;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
    {
        write(fd, buffer, buffer_index);
        buffer_index = 0;
    }
    if (c != BUF_FLUSH)
        buffer[buffer_index++] = c;
    return (1);
}

/**
 * _putsfd - Outputs a string to a given file descriptor.
 * @str: String to output.
 * @fd: File descriptor to write to.
 * Return: Total number of characters written.
 */
int _putsfd(char *str, int fd)
{
    int char_count = 0;

    if (!str)
        return (0);
    while (*str)
    {
        char_count += _putfd(*str++, fd);
    }
    return (char_count);
}

