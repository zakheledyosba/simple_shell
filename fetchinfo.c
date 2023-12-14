#include "shell.h"


/**
 * clear_info -"initializes info_t struct
 * @info: struct address"
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info -"initializes info_t struct
 * @info: struct address
 * @av: argument vector"
 *
 */

void set_info(info_t *info, char **av)
{
	int o;

	o = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");

		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (o = 0; info->argv && info->argv[o]; o++)
			;
		info->argc = o;
		replace_alias(info);
		replace_vars(info);
	}
}
