#include "shell.h"

/**
 * _strlen - Calculates the length of a given string.
 * @s: String to calculate the length of.
 * Return: The length of the string as an integer.
 */
int _strlen(char *s)
{
    int length = 0;

    if (!s)
        return 0;

    while (*s++)
        length++;
    return length;
}

/**
 * _strcmp - Compares two strings lexicographically.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 == *s2) ? 0 : (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Determines if one string starts with another.
 * @haystack: The main string to search within.
 * @needle: The substring to search for at the beginning of haystack.
 * Return: Pointer to the character following the found substring, or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return NULL;
    return (char *)haystack;
}

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string where the source string is appended.
 * @src: Source string to append to the destination.
 * Return: Pointer to the concatenated destination string.
 */
char *_strcat(char *dest, char *src)
{
    char *dest_start = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return dest_start;
}

