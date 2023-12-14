#include "shell.h"


/**
 * _strcpy -"copies a string
 * @dest: the destination
 * @src: the source"
 *
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int o;

	o = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[o])
	{
		dest[o] = src[o];
		o++;
	}
	dest[o] = 0;
	return (dest);
}

/**
 * _strdup -"duplicates a string
 * @str: the string to duplicate"
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	int lenth;
	char *ret;

	lenth = 0;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lenth++;

	ret = malloc(sizeof(char) * (lenth + 1));

	if (!ret)
		return (NULL);
	for (lenth++; lenth--;)
		ret[lenth] = *--str;
	return (ret);
}

/**
 * _puts -"prints an input string
 * @str: the string to be printed"
 *
 * Return: Nothing
 */

void _puts(char *str)
{
	int o;

	o = 0;

	if (!str)
		return;
	while (str[o] != '\0')
	{
		_putchar(str[o]);
		o++;
	}
}

/**
 * _putchar -"writes the character c to stdout
 * @c: The character to print"
 *
 * Return: On success 1. -1 on error
 *
 */

int _putchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int o;

	if (c == BUF_FLUSH || o >= WRITE_BUF_SIZE)
	{
		write(1, buf, o);
		o = 0;
	}
	if (c != BUF_FLUSH)
		buf[o++] = c;
	return (1);
}
