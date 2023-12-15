#include "shell.h"

/**
 * _myhistory - Presents the history of executed commands.
 *              Each command is numbered starting from 0.
 * @info: Structure with command arguments, ensuring uniform function signature.
 * Return: Always returns 0.
 */
int _myhistory(info_t *info)
{
    print_list(info->history);
    return (0);
}

/**
 * unset_alias - Removes an existing alias.
 * @info: Parameter structure.
 * @str: Alias string to be removed.
 * Return: 0 on success, 1 if alias is not found.
 */
int unset_alias(info_t *info, char *str)
{
    char *alias_position, alias_char;
    int result;

    alias_position = _strchr(str, '=');
    if (!alias_position)
        return (1);
    alias_char = *alias_position;
    *alias_position = '\0';
    result = delete_node_at_index(&(info->alias),
        get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
    *alias_position = alias_char;
    return (result);
}

/**
 * set_alias - Creates or updates an alias.
 * @info: Parameter structure.
 * @str: String defining the alias.
 * Return: 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *str)
{
    char *equal_sign_position;

    equal_sign_position = _strchr(str, '=');
    if (!equal_sign_position)
        return (1);
    if (!*++equal_sign_position)
        return (unset_alias(info, str));

    unset_alias(info, str);
    return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Outputs an alias to standard output.
 * @node: Alias node to be printed.
 * Return: 0 on success, 1 if alias node is NULL.
 */
int print_alias(list_t *node)
{
    char *alias_split = NULL, *alias_iter = NULL;

    if (node)
    {
        alias_split = _strchr(node->str, '=');
        for (alias_iter = node->str; alias_iter <= alias_split; alias_iter++)
            _putchar(*alias_iter);
        _putchar('\'');
        _puts(alias_split + 1);
        _puts("'\n");
        return (0);
    }
    return (1);
}

/**
 * _myalias - Implements functionality similar to the 'alias' builtin.
 * @info: Structure containing command arguments for uniformity.
 * Return: Always 0.
 */
int _myalias(info_t *info)
{
    int arg_index = 0;
    char *equal_sign = NULL;
    list_t *current_node = NULL;

    if (info->argc == 1)
    {
        current_node = info->alias;
        while (current_node)
        {
            print_alias(current_node);
            current_node = current_node->next;
        }
        return (0);
    }
    for (arg_index = 1; info->argv[arg_index]; arg_index++)
    {
        equal_sign = _strchr(info->argv[arg_index], '=');
        if (equal_sign)
            set_alias(info, info->argv[arg_index]);
        else
            print_alias(node_starts_with(info->alias, info->argv[arg_index], '='));
    }

    return (0);
}

