#include "shell.h"


/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv -"gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: environmental variable name"
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node;
	char *a;

	node = info->env;

	while (node != NULL)
	{
		a = starts_with(node->str, name);
		if (a != NULL && *a != '\0')
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - "Initialize a new environment variable,
 * @info: Structure containing potential arguments."
 *  Return: Always 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Invaild number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv -"Remove an environment variable
 * @info: Structure containing potential arguments."
 *  Return: Always 0
 */

int _myunsetenv(info_t *info)
{
	int o;

	if (info->argc == 1)

	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (o = 1; o <= info->argc; o++)
		_unsetenv(info, info->argv[o]);

	return (0);
}

/**
 * populate_env_list -"populates env linked list
 * @info: Structure containing potential arguments."
 * Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node;
	size_t o;

	node = NULL;

	for (o = 0; environ[o]; o++)
		add_node_end(&node, environ[o], 0);
	info->env = node;
	return (0);
}
