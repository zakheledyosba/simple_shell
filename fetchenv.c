#include "shell.h"


/**
 * get_environ -"returns the string array copy of our environ
 * @info: Structure containing potential arguments."
 * Return: Always 0
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
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 * @var: the string env var property
 * Return:1 on delete, otherwise 0
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node;
	size_t o;
	char *a;

	node = info->env;
	o = 0;

	if (!node || !var)
		return (0);

	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), o);
			o = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		o++;
	}
	return (info->env_changed);
}

/**
 * _setenv - "Initialize a new environment variable.
 * @info: Structure containing potential arguments.
 * @var: the string env var property
 * @value: the string env var value"
 *
 * Return: Always 0
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf;
	list_t *node;
	char *a;

	buf = NULL;

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);

	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;

	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
