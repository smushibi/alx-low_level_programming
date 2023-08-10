#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers from min to max
 * @min: The starting value
 * @max: The ending value
 *
 * Return: Pointer to the newly created array, NULL on
 * failure or invalid input
 */
int *array_range(int min, int max)
{
int *arr;
int i;
if (min > max)
return (NULL);
arr = malloc((max - min + 1) * sizeof(int));
if (arr == NULL)
return (NULL);
for (i = 0; min <= max; min++, i++)
{
arr[i] = min;
}
return (arr);
}
