
#include <stdio.h>
#include <stdlib.h>
/**
 * create_array - Create an array of chars and
 *                initialize it with a specific char.
 * @size: The size of the array.
 * @c: The char to initialize the array with.
 * Returns: A pointer to the created array, or NULL if size is 0.
 */
char *create_array(unsigned int size, char c)
{
char *array;
if (size == 0)
{
return (NULL);
}
array = (char *)malloc(sizeof(char) * size);
if (array == NULL)
{
return (NULL);
}
for (unsigned int i = 0; i < size; i++)
{
array[i] = c;
}
return (array);
}
