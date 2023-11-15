#include "shell.h"

/**
 * swapch - swaps &, |
 * @command: command string
 * @bl: type of swap
 * 
 * Return: string
 */
char *swapch(char *command, int bl)
{
	int i;

	if (bl == 0)
	{
		i = 0;
		while (command[i])
		{
			if (command[i] == '&')
			{
				if (command[i + 1] != '&')
					command[i] = 12;
				else
					i++;
			}

			if (command[i] == '|')
			{
				if (command[i + 1] != '|')
					command[i] = 16;
				else
					i++;
			}
			i++;
		}
	}
	else
	{
		for (i = 0; command[i]; i++)
		{
			command[i] = (command[i] == 12 ? '&' : command[i]);
			command[i] = (command[i] == 16 ? '|' : command[i]);
		}
	}
	return (command);
}

/**
 * addnew - add new nodes in the lists
 *
 * @start_s: head of separator list
 * @start_l: head of command lines list
 * @command: command string
 * Return: no return
 */
void addnew(sep **start_s, line_li **start_l, char *command)
{
	char *line;
	int i;

	command = swapch(command, 0);
	for (i = 0; command[i]; i++)
	{
		if (command[i] == ';')
			add_node_end_sept(start_s, command[i]);

		if (command[i] == '|' || command[i] == '&')
		{
			add_node_end_sept(start_s, command[i]);
			i++;
		}
	}

	line = strtok(command, ";|&");
	do {
		line = swapch(line, 1);
		add_node_end_ln(start_l, line);
		line = strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * go_to_next - go to the next command line 
 *
 * @list_s: separator list
 * @list_l: command line list
 * @dat: data structure
 */
void go_to_next(sep **list_s, line_li **list_l, shell_dat *dat)
{
	line_li *ls_l = *list_l;
	sep *ls_s = *list_s;
	int it = 1;

	while (ls_s != NULL && it)
	{
		if (dat->status == 0)
		{
			if (ls_s->separator == ';' || ls_s->separator == '&')
				it = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == ';' || ls_s->separator == '|')
				it = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !it)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - splits command lines
 *
 * @dat: data structure
 * @command: command string
 * Return: 1 to continue, 0 to exit
 */
int split_commands(shell_dat *dat, char *command)
{

	sep *start_s, *list_s;
	line_li *start_l, *list_l;
	int loop;

	start_s = NULL;
	start_l = NULL;

	addnew(&start_s, &start_l, command);

	list_s = start_s;
	list_l = start_l;

	while (list_l != NULL)
	{
		dat->command = list_l->line;
		dat->args = split(dat->command);
		loop = exec_line(dat);
		free(dat->args);

		if (loop == 0)
			break;

		go_to_next(&list_s, &list_l, dat);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	sep_free(&start_s);
	line_free(&start_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split - tokenizes the command command
 *
 * @command: command string.
 * Return: splitted string
 */
char **split(char *command)
{
	char *token;
	char **toks;
	size_t size, i;

	size = 128;
	toks = malloc(sizeof(char *) * (size));
	if (toks == NULL)
		exit(EXIT_FAILURE);

	token = strtok(command, " \t\r\n\a");
	toks[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == size)
		{
			size += 128;
			toks = _reallocdp(toks, i, sizeof(char *) * size);
			if (toks == NULL)
				exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\r\n\a");
		toks[i] = token;
	}

	return (toks);
}
