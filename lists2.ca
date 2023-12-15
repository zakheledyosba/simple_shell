#include "shell.h"


/**
 * list_len -"determines length of linked list
 * @h: pointer to first node"
 *
 * Return: size of list
 */

size_t list_len(const list_t *h)
{
	size_t o;

	o = 0;

	while (h)
	{
		h = h->next;
		o++;
	}
	return (o);
}

/**
 * list_to_strings -"returns an array of strings of the list->str
 * @head: pointer to first node"
 *
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t o = list_len(head), k;

	char **strs;
	char *str;

	node = head;

	o = list_len(head);

	if (!head || !o)
		return (NULL);
	strs = malloc(sizeof(char *) * (o + 1));

	if (!strs)
		return (NULL);

	for (o = 0; node; node = node->next, o++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (k = 0; k < o; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[o] = str;
	}
	strs[o] = NULL;
	return (strs);
}

/**
 * print_list -"prints all elements of a list_t linked list
 * @h: pointer to first node"
 *
 * Return: size of list
 */

size_t print_list(const list_t *h)
{
	size_t o;

	o = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		o++;
	}
	return (o);
}

/**
 * node_starts_with -"returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match"
 *
 * Return: match node or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *a;

	a = NULL;

	while (node)
	{
		a = starts_with(node->str, prefix);

		if (a && ((c == -1) || (*a == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index -"gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node"
 *
 * Return: index of node or -1
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t o;

	o = 0;

	while (head)
	{
		if (head == node)
			return (o);
		head = head->next;
		o++;
	}
	return (-1);
}
