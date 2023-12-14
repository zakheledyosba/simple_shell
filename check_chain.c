#include "shell.h"

void check_chain(info_t *info, char *buf, size_t *k, size_t o, size_t len)
{
    printf("Checking chain from index %ld to %ld:\n", o, len - 1);
    for (size_t i = o; i < len; ++i)
	{
		putchar(buf[i]);
	}

	putchar('\n');
}
