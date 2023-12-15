#include "shell.h"


/**
 * strtow - "splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string"
 *
 * Return: a pointer to an array of strings.
 */

char **strtow(char *str, char *d)
{
	int o, h, l, n, dgtwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (o = 0; str[o] != '\0'; o++)
		if (!is_delim(str[o], d) && (is_delim(str[o + 1], d) || !str[o + 1]))
			dgtwords++;

	if (dgtwords == 0)
		return (NULL);
	s = malloc((1 + dgtwords) * sizeof(char *));

	if (!s)
		return (NULL);

	for (o = 0, h = 0; h < dgtwords; h++)
	{
		while (is_delim(str[o], d))
			o++;
		l = 0;

		while (!is_delim(str[o + l], d) && str[o + l])
			l++;
		s[h] = malloc((l + 1) * sizeof(char));

		if (!s[h])
		{
			for (l = 0; l < h; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}

		for (n = 0; n < l; n++)
			s[h][n] = str[o++];
		s[h][n] = 0;
	}
	s[h] = NULL;
	return (s);
}

/**
 * strtow2 -"splits a string into words
 * @str: the input string
 * @d: the delimeter"
 *
 * Return: a pointer to an array of strings
 */

char **strtow2(char *str, char d)
{
	int o, h, l, n, dgtwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);

	for (o = 0; str[o] != '\0'; o++)
		if ((str[o] != d && str[o + 1] == d) ||
		    (str[o] != d && !str[o + 1]) || str[o + 1] == d)
			dgtwords++;

	if (dgtwords == 0)
		return (NULL);
	s = malloc((1 + dgtwords) * sizeof(char *));

	if (!s)
		return (NULL);

	for (o = 0, h = 0; h < dgtwords; h++)
	{
		while (str[o] == d && str[o] != d)
			o++;
		l = 0;

		while (str[o + l] != d && str[o + l] && str[o + l] != d)
			l++;
		s[h] = malloc((l + 1) * sizeof(char));

		if (!s[h])
		{
			for (l = 0; l < h; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}

		for (n = 0; n < l; n++)
			s[h][n] = str[o++];
		s[h][n] = 0;
	}
	s[h] = NULL;
	return (s);
}
