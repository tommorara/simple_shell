#include "shell.h"

/**
 * _strncpy - Copies characters from one string to another.
 * @dest: Destination string where characters are copied to.
 * @src: Source string from where characters are copied.
 * @n: Number of characters to copy.
 * Return: Pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    for (i = 0; src[i] != '\0' && i < n - 1; i++)
    {
        dest[i] = src[i];
    }
    for (j = i; j < n; j++)
    {
        dest[j] = '\0';
    }
    return s;
}

/**
 * _strncat - Concatenates two strings with a limit on the number of characters.
 * @dest: First string and the destination for concatenation.
 * @src: Second string to be appended.
 * @n: Maximum number of characters to append.
 * Return: Pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
    int dest_len = 0, j = 0;
    char *s = dest;

    while (dest[dest_len] != '\0')
        dest_len++;
    while (src[j] != '\0' && j < n)
    {
        dest[dest_len] = src[j];
        dest_len++;
        j++;
    }
    if (j < n)
        dest[dest_len] = '\0';
    return s;
}

/**
 * _strchr - Searches for a character in a string.
 * @s: String to be searched.
 * @c: Character to look for.
 * Return: Pointer to the first occurrence of the character, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return s;
        s++;
    }
    return (c == '\0') ? s : NULL;
}

