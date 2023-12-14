#include "shell.h"


/**
 * is_chain -"test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf"
 *
 * Return: 1 if chain delimeter, otherwise 0
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t h;

	h = *p;

	if (buf[h] == '|' && buf[h + 1] == '|')
	{
		buf[h] = 0;
		h++;
		info->cmd_buf_type = CMD_OR;
	}

	else if (buf[h] == '&' && buf[h + 1] == '&')
	{
		buf[h] = 0;
		h++;
		info->cmd_buf_type = CMD_AND;
	}

	else if (buf[h] == ';')
	{
		buf[h] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = h;
	return (1);
}

/**
 * replace_alias -"replaces an aliases in the tokenized string
 * @info: the parameter struct"
 *
 * Return: 1 if replaced, otherwise 0
 */

int replace_alias(info_t *info)
{
	int o;
	list_t *node;
	char *p;

	for (o = 0; o < 10; o++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');

		if (!p)
			return (0);
		p = _strdup(p + 1);

		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars -"replaces vars in the tokenized string
 * @info: the parameter struct"
 *
 * Return: 1 if replaced, otherwise 0
 */

int replace_vars(info_t *info)
{
	int o;
	list_t *node;

	o = 0;

	for (o = 0; info->argv[o]; o++)
	{
		if (info->argv[o][0] != '$' || !info->argv[o][1])
			continue;

		if (!_strcmp(info->argv[o], "$?"))
		{
			replace_string(&(info->argv[o]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}

		if (!_strcmp(info->argv[o], "$$"))
		{
			replace_string(&(info->argv[o]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}

		node = node_starts_with(info->env, &info->argv[o][1], '=');
		if (node)
		{
			replace_string(&(info->argv[o]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[o], _strdup(""));

	}
	return (0);
}

/**
 * replace_string -"replaces string
 * @old: address of old string
 * @new: new string"
 *
 * Return: 1 if replaced, otherwise 0
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
