#include "shell.h"


/**
 * _myhistory -"displays the history list, one command by line, precedecture
 * @info: Structure containing potential arguments."
 * Return: Always 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias -"sets alias to string
 * @info: parameter struct
 * @str: the string alias"
 *
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *a, v;
	int ter;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	v = *a;
	*a = 0;
	ter = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*a = v;
	return (ter);
}

/**
 * set_alias - "sets alias to string
 * @info: parameter struct
 * @str: the string alias"
 *
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *a;

	a = _strchr(str, '=');
	if (!a)
		return (1);

	if (!*++a)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias -"prints an alias string
 * @node: the alias node"
 *
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *a, *s;

	a = NULL, s = NULL;

	if (node)
	{
		a = _strchr(node->str, '=');
		for (s = node->str; s <= a; s++)
			_putchar(*s);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");

		return (0);
	}
	return (1);
}

/**
 * _myalias -"mimics the alias builtin
 * @info: Structure containing potential arguments."
 *  Return: Always 0
 */

int _myalias(info_t *info)
{
	int o = 0;
	char *a = NULL;
	list_t *node = 0;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (o = 1; info->argv[o]; o++)
	{
		a = _strchr(info->argv[o], '=');
		if (a)
			set_alias(info, info->argv[o]);
		else
			print_alias(node_starts_with(info->alias, info->argv[o], '='));
	}

	return (0);
}
