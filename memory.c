#include "shell.h"


/**
 * _memcpy - copy str from src to dest
 *
 * @dest: pointer to the destination to copy the str to
 *
 * @src: poiter to the source to copy the str from
 *
 * @num_bytes: number of bytes to copy
 *
 * Return: pointer to the dest
 */

void *_memcpy(void *dest, const void *src, size_t num_bytes)
{
	char *d = dest;
	const char *s = src;
	size_t i = 0;


	while (i < num_bytes)
	{
		d[i] = s[i];
		i++;
	}

	return (dest);
}





/**
 * _realloc - reallocate memory size for a buffer
 *
 * @ptr: pointer to buffer to resize
 *
 * @new_size: the new sizwe to be allocated
 *
 * Return: pointer to the newly allocated variable
 */


void *_realloc(void *ptr, size_t new_size)
{
	void *new_ptr;
	size_t copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		copy_size = new_size < sizeof(ptr) ? new_size : sizeof(ptr);
		_memcpy(new_ptr, ptr, copy_size);

		free(ptr);
	}

	return (new_ptr);
}
