#include "shell.h"

/**
 * _myenv - Outputs the current environment settings.
 * @info: Struct with potential arguments for consistent function prototype.
 * Return: Always returns 0.
 */
int _myenv(info_t *info)
{
    print_list_str(info->env);
    return (0);
}

/**
 * _getenv - Retrieves the value of a specified environment variable.
 * @info: Struct with potential arguments for consistent function prototype.
 * @name: Name of the environment variable.
 * Return: Pointer to the value or NULL if not found.
 */
char *_getenv(info_t *info, const char *name)
{
    list_t *env_node = info->env;
    char *value_ptr;

    while (env_node)
    {
        value_ptr = starts_with(env_node->str, name);
        if (value_ptr && *value_ptr)
            return (value_ptr);
        env_node = env_node->next;
    }
    return (NULL);
}

/**
 * _mysetenv - Sets or updates an environment variable.
 * @info: Struct containing arguments for uniform function signature.
 * Return: 0 on successful set/update, 1 on failure.
 */
int _mysetenv(info_t *info)
{
    if (info->argc != 3)
    {
        _eputs("Invalid number of arguments.\n");
        return (1);
    }
    if (_setenv(info, info->argv[1], info->argv[2]))
        return (0);
    return (1);
}

/**
 * _myunsetenv - Removes an environment variable.
 * @info: Struct with potential arguments for consistent function prototype.
 * Return: Always returns 0.
 */
int _myunsetenv(info_t *info)
{
    int arg_index;

    if (info->argc == 1)
    {
        _eputs("Insufficient arguments.\n");
        return (1);
    }
    for (arg_index = 1; arg_index < info->argc; arg_index++)
        _unsetenv(info, info->argv[arg_index]);

    return (0);
}

/**
 * populate_env_list - Fills the environment variables list.
 * @info: Struct containing arguments for uniform function signature.
 * Return: Always returns 0.
 */
int populate_env_list(info_t *info)
{
    list_t *new_node = NULL;
    size_t env_index;

    for (env_index = 0; environ[env_index]; env_index++)
        add_node_end(&new_node, environ[env_index], 0);
    info->env = new_node;
    return (0);
}

