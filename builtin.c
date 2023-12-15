#include "shell.h"

/**
 * _myexit - Handles the exit operation of the shell.
 * @info: Pointer to the info structure holding command arguments.
 *        Ensures uniform function signature.
 * Return: -2 to indicate exit, 1 for error in exit argument.
 */
int _myexit(info_t *info)
{
    int exit_check;

    if (info->argv[1])  /* Checks for additional exit arguments */
    {
        exit_check = _erratoi(info->argv[1]);
        if (exit_check == -1)
        {
            info->status = 2;
            print_error(info, "Invalid number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return (1);
        }
        info->err_num = _erratoi(info->argv[1]);
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}

/**
 * _mycd - Changes the current working directory.
 * @info: Structure holding the command arguments.
 * Return: 0 on success, 1 on failure.
 */
int _mycd(info_t *info)
{
    char *current_dir, *target_dir, buffer[1024];
    int change_dir_status;

    current_dir = getcwd(buffer, 1024);
    if (!current_dir)
        _puts("Error: Unable to get current directory.\n");
    
    if (!info->argv[1])
    {
        target_dir = _getenv(info, "HOME=");
        if (!target_dir)
            change_dir_status = chdir((target_dir = _getenv(info, "PWD=")) ? target_dir : "/");
        else
            change_dir_status = chdir(target_dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(current_dir);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
        change_dir_status = chdir((target_dir = _getenv(info, "OLDPWD=")) ? target_dir : "/");
    }
    else
        change_dir_status = chdir(info->argv[1]);

    if (change_dir_status == -1)
    {
        print_error(info, "Unable to cd to ");
        _eputs(info->argv[1]), _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * _myhelp - Displays help information for shell commands.
 * @info: Structure holding the command arguments.
 * Return: Always returns 0.
 */
int _myhelp(info_t *info)
{
    char **argument_list;

    argument_list = info->argv;
    _puts("Help functionality is active. Implementation pending.\n");
    if (0)
        _puts(*argument_list); /* Temporary workaround */
    return (0);
}

