#include "shell.h"


void free_info(info_t *info, int free_argv)
{
    if (info == NULL)
	{
        return;
	}

	if (free_argv && info->argv != NULL) 
	{
		int o = 0;
		while (info->argv[o] != NULL)
		{
			free(info->argv[o]);
			o++;
		}

		free(info->argv);
	}

	free(info->path);
    free(info);
}
