#include "shell.h"
/**
 * _reallocdp - reallocates a memory space for a double pointer.
 *
 * @ptr: double pointer
 * @size_o: size of the allocated space of ptr.
 * @size_new: new size of the new memory block.
 * Return: ptr
 */
char **_reallocdp(char **ptr, unsigned int size_o, unsigned int size_new)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * size_new));

	if (size_new == size_o)
		return (ptr);

	newptr = malloc(sizeof(char *) * size_new);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < size_o; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
