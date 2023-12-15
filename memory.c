#include "shell.h"

/**
 * bfree - Deallocates memory and sets pointer to NULL.
 * @ptr: Address of the pointer to be deallocated.
 * Return: 1 if memory is successfully freed, 0 otherwise.
 */
int bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return (1);
    }
    return (0);
}

