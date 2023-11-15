#include "shell.h"

/**
 * add_node_end_sept - adds a new node at the end
 * of a sep
 *
 * @start: start of the linked list.
 * @sepr: separator found (; | &).
 * Return: address of the start.
 */
sep *add_node_end_sept(sep **start, char sepr)
{
	sep *new, *temp;

	new = malloc(sizeof(sep));
	if (new == NULL)
		return (NULL);

	new->separator = sepr;
	new->next = NULL;
	temp = *start;

	if (temp == NULL)
	{
		*start = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*start);
}

/**
 * sep_free - frees a sep
 * @start: start of the linked list.
 */
void sep_free(sep **start)
{
	sep *curr, *temp;

	if (start != NULL)
	{
		curr = *start;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*start = NULL;
	}
}

/**
 * add_node_end_ln - adds a command at the end
 * of a line_li
 *
 * @start: start of the linked list.
 * @line: command line.
 *
 * Return: start
 */
line_li *add_node_end_ln(line_li **start, char *line)
{
	line_li *new, *temp;

	new = malloc(sizeof(line_li));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *start;

	if (temp == NULL)
	{
		*start = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*start);
}

/**
 * line_free - frees a line_li
 *
 * @start: start of the linked list
 */
void line_free(line_li **start)
{
	line_li *curr, *temp;

	if (start != NULL)
	{
		curr = *start;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*start = NULL;
	}
}
