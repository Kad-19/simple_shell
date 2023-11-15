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
/**
 * _realloc - reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @size_o: size, in bytes, of the allocated space of ptr.
 * @size_new: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if size_new == size_o, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int size_o, unsigned int size_new)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(size_new));

	if (size_new == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (size_new == size_o)
		return (ptr);

	newptr = malloc(size_new);
	if (newptr == NULL)
		return (NULL);

	if (size_new < size_o)
		memcpy(newptr, ptr, size_new);
	else
		memcpy(newptr, ptr, size_o);

	free(ptr);
	return (newptr);
}
