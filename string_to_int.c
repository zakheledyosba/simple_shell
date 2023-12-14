#include "shell.h"


/**
 * interactive - returns true if shell is interactive mode
 * @info: address of struct
 * Return: 1 if true, otherwise 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: char checked
 * @delim: the string delimeter
 * Return: 1 if true, 0 otherwise
 *
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
		{
			return (1);
		}
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The char to input
 *Return: 1 if true , 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: strng to be converted
 *Return: 0 if no numbers in string, 1 otherwise
 */

int _atoi(char *s)
{
	int o, sign, flag, output;
	unsigned int result;

	sign = 1, result = 0, flag = 0;

	for (o = 0;  s[o] != '\0' && flag != 2; o++)
	{
		if (s[o] == '-')
			sign *= -1;
		if (s[o] >= '0' && s[o] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[o] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
