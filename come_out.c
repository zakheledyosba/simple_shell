#include "shell.h"


/**
 * _strncpy -"copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied"
 * Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int o = 0, k;
	char *d = dest;

	while (src[o] != '\0' && o < n - 1)
	{
		dest[o] = src[o];
		o++;
	}

	if (o < n)
	{
		k = o;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (d);
}

/**
 * _strncat -"concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the maximum amount of bytes to be used"
 * Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int o = 0, k = 0;
	char *d = dest;

	while (dest[o] != '\0')
		o++;

	while (src[k] != '\0' && k < n)
	{
		dest[o] = src[k];
		o++;
		k++;
	}
	if (k < n)
		dest[o] = '\0';
	return (d);
}

/**
 * _strchr -"locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for"
 * Return: (s) a pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}
