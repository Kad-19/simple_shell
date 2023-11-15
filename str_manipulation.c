#include "shell.h"
/**
 * is_digit - defines if string passed is a number
 *
 * @str: string
 * Return: 1 if string is a number, 0 otherwise
 */
int is_digit(const char *str)
{
	unsigned int i = 0;

	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
/**
 * conv_itoa - converts int to string
 * @num: type int number
 * Return: String.
 */
char *conv_itoa(int num)
{
	char *buffer;
	unsigned int no;
	int len = dig_len(num);

	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + len) = '\0';

	if (num < 0)
	{
		no = num * -1;
		buffer[0] = '-';
	}
	else
	{
		no = num;
	}

	len--;
	do
	{
		*(buffer + len) = (no % 10) + '0';
		no = no / 10;
		len--;
	} while (no > 0);
	return (buffer);
}

/**
 * conv_atoi - converts string to an integer
 * @s: input string.
 *
 * Return: integer.
 */
int conv_atoi(char *s)
{
	unsigned int num = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + num) != '\0')
	{
		if (size > 0 && (*(s + num) < '0' || *(s + num) > '9'))
			break;

		if (*(s + num) == '-')
			pn *= -1;

		if ((*(s + num) >= '0') && (*(s + num) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		num++;
	}

	for (i = num - size; i < num; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
/**
 * dig_len - len of a number
 * @n: number.
 *
 * Return: len of a number
 */
int dig_len(int n)
{
	unsigned int no;
	int len = 1;

	if (n < 0)
	{
		len++;
		no = n * -1;
	}
	else
	{
		no = n;
	}
	while (no > 9)
	{
		len++;
		no = no / 10;
	}

	return (len);
}
