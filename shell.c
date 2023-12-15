#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * execute_command - Execute a command in a child process.
 * @command: The command to be executed.
 * Return: The exit status of the command.
 */
int execute_command(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
	perror("fork");
	return (EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
	/* Child process */
		char *args[] = {NULL, NULL};

		args[0] = command;
		execve(command, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
	/* Parent process */
	waitpid(child_pid, &status, 0);
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
		return (EXIT_FAILURE);
	}
}

/**
 * main - The main function of the shell.
 * Return: Always 0.
 */
int main(void)
{
	char buffer[BUFFER_SIZE];
	int status;

	while (1)
	{
	display_prompt();

	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
	{
		printf("\n");
	/* End of file (Ctrl+D) */
		break;
	}

	buffer[strcspn(buffer, "\n")] = '\0';

	if (strcmp(buffer, "exit") == 0)
	{
		break;
	}

		status = execute_command(buffer);
	if (status == EXIT_FAILURE)
	{
		fprintf(stderr, "./shell: No such file or directory\n");
	}
	}

	return (EXIT_SUCCESS);
}

