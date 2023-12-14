#include "shell.h"


/**
 * _erratoi - "converts a string to an integer
 * @s: the string to be converted"
 * Return: 0 if no numbers in string, otherwise 1
 */

int _erratoi(char *s)
{
	int o = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	while (s[o] != '\0')
	{
		if (s[o] >= '0' && s[o] <= '9')
		{
			result *= 10;
			result += (s[o] - '0');
			if (result > INT_MAX)
				return (-1);
		}
			return (-1);
			o++;
	}
	return (result);
}

/**
 * print_error -"prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type"
 * Return: 0 if no numbers in string, otherwise -1
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - "function prints a decimal number
 * @input: the input
 * @fd: the filedescriptor to write to"
 *
 * Return: number of characters printed
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int o, sum = 0;
	unsigned int _asd_;
	unsigned int now;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_asd_ = -input;
		__putchar('-');
		sum++;
	}
	else
		_asd_ = input;
	now = _asd_;
	for (o = 1000000000; o > 1; o /= 10)
	{
		if (_asd_ / o)
		{
			__putchar('0' + now / o);
			sum++;
		}
		now %= o;
	}
	__putchar('0' + now);
	sum++;

	return (sum);
}

/**
 * convert_number - "converter function
 * @num: number
 * @base: base
 * @flags: argument flags"
 *
 * Return: string
 */

char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign, *ptr;
	unsigned long n;

	sign = 0;
	n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments -"function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify"
 *
 * Return: Always 0;
 */

void remove_comments(char *buf)
{
	int o;

	for (o = 0; buf[o] != '\0'; o++)
		if (buf[o] == '#' && (!o || buf[o - 1] == ' '))
		{
			buf[o] = '\0';
			break;
		}
}
