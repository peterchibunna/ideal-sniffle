#include "shell.h"
/**
 *is_builtin- checks to see whether it's a built in function
 *@cmd: tokenized user input
 *@buf: line derived from getline function
 *Return: 1 if cmd executed 0 if cmd is not executed
 */
int is_builtin(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
	{
		return (1);
	}
	else if (**cmd == '/')
	{
		interpret(cmd[0], cmd);
		return (1);
	}
	else if(str_compare(*cmd, "exit") == true)
	{
		exit(0);
	}
	return (0);
}
