#include "shell.h"

/**
 * input_buf -"buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var"
 *
 * Return: bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t t;
	size_t len_a;

	t = 0, len_a = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		t = getline(buf, &len_p, stdin);
#else
		t = _getline(info, buf, &len_a);
#endif
		if (t > 0)
		{
			if ((*buf)[t - 1] == '\n')
			{
				(*buf)[t - 1] = '\0';
				t--;
			}

			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = t;
				info->cmd_buf = buf;
			}
		}
	}
	return (t);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t o, k;
	static size_t len;
	ssize_t t;
	char **buf_p = &(info->arg), *a;

	t = 0;

	_putchar(BUF_FLUSH);
	t = input_buf(info, &buf, &len);

	if (t == -1)
		return (-1);
	if (len)
	{
		k = o;
		a = buf + o;

		check_chain(info, buf, &k, o, len);

		while (k < len)
		{
			if (is_chain(info, buf, &k))
				break;
			k++;
		}

		o = k + 1;
		if (o >= len)
		{
			o = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = a;
		return (_strlen(a));
	}

	*buf_p = buf;
	return (t);
}

/**
 * read_buf -"reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size"
 * Return: r
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t t;

	t = 0;

	if (*i)
		return (0);
	t = read(info->readfd, buf, READ_BUF_SIZE);

	if (t >= 0)
		*i = t;
	return (t);
}

/**
 * _getline -"gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL"
 *
 * Return: s
 */

int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t o, len;
	size_t l;
	ssize_t t = 0, d = 0;
	char *a = NULL, *new_a = NULL, *v;

	t = 0, d = 0;
	a = *ptr;

	if (a && length)
		d = *length;
	if (o == len)
		o = len = 0;

	t = read_buf(info, buf, &len);

	if (t == -1 || (t == 0 && len == 0))
		return (-1);

	v = _strchr(buf + o, '\n');
	l = v ? 1 + (unsigned int)(v - buf) : len;
	new_a = _realloc(a, d, d ? d + l : l + 1);

	if (!new_a)
		return (a ? free(a), -1 : -1);

	if (d)
		_strncat(new_a, buf + o, l - o);
	else
		_strncpy(new_a, buf + o, l - o + 1);

	d += l - o;
	o = l;
	a = new_a;

	if (length)
		*length = d;
	*ptr = a;
	return (d);
}

/**
 * sigintHandler -"blocks ctrl-C
 * @sig_num: the signal number"
 *
 * Return: void
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
