#include "shell.h"

void check_chain(info_t *info, char *buf, size_t *k, size_t o, size_t len)
{

	size_t i;
	printf("Checking chain from index %lu to %lu:\n", o, len - 1);
	for (i = o; i < len; ++i)
	{
		*k = i;
		printf("info value:%d\n", info->readfd);
		putchar(buf[i]);
	}

	putchar('\n');
}
