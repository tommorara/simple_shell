#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: Destination buffer where the string is copied to.
 * @src: Source string to be copied.
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
    int index = 0;

    if (dest == src || !src)
        return dest;
    while (src[index])
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
    return dest;
}

/**
 * _strdup - Creates a duplicate of the given string.
 * @str: String to be duplicated.
 * Return: Pointer to the newly allocated string, or NULL on failure.
 */
char *_strdup(const char *str)
{
    int len = 0;
    char *duplicate;

    if (!str)
        return NULL;
    while (str[len])
        len++;
    duplicate = malloc(sizeof(char) * (len + 1));
    if (!duplicate)
        return NULL;
    while (len >= 0)
    {
        duplicate[len] = str[len];
        len--;
    }
    return duplicate;
}

/**
 * _puts - Outputs a string to stdout.
 * @str: String to be printed.
 * Return: None.
 */
void _puts(char *str)
{
    int index = 0;

    if (!str)
        return;
    while (str[index] != '\0')
    {
        _putchar(str[index]);
        index++;
    }
}

/**
 * _putchar - Writes a character to stdout.
 * @c: Character to be written.
 * Return: 1 on success, -1 on error with errno set.
 */
int _putchar(char c)
{
    static int buf_index = 0;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || buf_index >= WRITE_BUF_SIZE)
    {
        write(1, buffer, buf_index);
        buf_index = 0;
    }
    if (c != BUF_FLUSH)
        buffer[buf_index++] = c;
    return 1;
}

