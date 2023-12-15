#include "shell.h"

/**
 * get_environ - Retrieves a copy of the environment string array.
 * @info: Struct containing arguments for consistent function signature.
 * Return: Pointer to the environment string array.
 */
char **get_environ(info_t *info)
{
    if (!info->environ || info->env_changed)
    {
        info->environ = list_to_strings(info->env);
        info->env_changed = 0;
    }

    return (info->environ);
}

/**
 * _unsetenv - Deletes an environment variable.
 * @info: Struct with potential arguments for consistent function prototype.
 * @var: Name of the environment variable to be removed.
 * Return: 1 if the variable was deleted, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
    list_t *node = info->env;
    size_t index = 0;
    char *prefix;

    if (!node || !var)
        return (0);

    while (node)
    {
        prefix = starts_with(node->str, var);
        if (prefix && *prefix == '=')
        {
            info->env_changed = delete_node_at_index(&(info->env), index);
            index = 0;
            node = info->env;
            continue;
        }
        node = node->next;
        index++;
    }
    return (info->env_changed);
}

/**
 * _setenv - Sets or updates an environment variable.
 * @info: Struct containing arguments for uniform function signature.
 * @var: Name of the environment variable.
 * @value: Value of the environment variable.
 * Return: 0 on success, 1 on failure.
 */
int _setenv(info_t *info, char *var, char *value)
{
    char *buffer = NULL;
    list_t *node;
    char *prefix;

    if (!var || !value)
        return (0);

    buffer = malloc(_strlen(var) + _strlen(value) + 2);
    if (!buffer)
        return (1);
    _strcpy(buffer, var);
    _strcat(buffer, "=");
    _strcat(buffer, value);
    node = info->env;
    while (node)
    {
        prefix = starts_with(node->str, var);
        if (prefix && *prefix == '=')
        {
            free(node->str);
            node->str = buffer;
            info->env_changed = 1;
            return (0);
        }
        node = node->next;
    }
    add_node_end(&(info->env), buffer, 0);
    free(buffer);
    info->env_changed = 1;
    return (0);
}

