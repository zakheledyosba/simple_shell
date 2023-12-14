#include "shell.h"


/**
 * _eputs - "prints an input string
 * @str: the string to be printed"
 * Return: Nothing
 */

void _eputs(char *str)
{
	int o;

	o = 0;

	if (!str)
		return;
	while (str[o] != '\0')
	{
		_eputchar(str[o]);
		o++;
	}
}

/**
 * _eputchar -"writes the character c to stderr
 * @c: The character to print"
 * Return: On success 1, -1 otherwise on error
 */

int _eputchar(char c)
{
	static int o;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || o >= WRITE_BUF_SIZE)
	{
		write(2, buf, o);
		o = 0;
	}

	if (c != BUF_FLUSH)
		buf[o++] = c;
	return (1);
}

/**
 * _putfd -"writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to"
 *
 * Return: On success 1, otherwise -1 on error
 */

int _putfd(char c, int fd)
{
	static int o;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || o >= WRITE_BUF_SIZE)
	{
		write(fd, buf, o);
		o = 0;
	}
	if (c != BUF_FLUSH)
		buf[o++] = c;
	return (1);
}

/**
 *_putsfd -"prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to"
 *
 * Return: the number of chars
 */

int _putsfd(char *str, int fd)
{
	int o;

	o = 0;

	if (!str)
		return (0);
	while (*str)
	{
		o += _putfd(*str, fd);
		++str;
	}
	return (o);
}
