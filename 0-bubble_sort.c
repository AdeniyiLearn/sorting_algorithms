#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: an integer array
 * @size: the size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int temp, i;
	size_t u, n;

	temp = '\0';
	for (u = 0; u < size; u++)
	{
		for (i = 0, n = 1; n < size; i++, n++)
		{
			if (*(array + i) > *(array + n))
			{
				temp = *(array + i);
				*(array + i) = *(array + n);
				*(array + n) = temp;
				print_array(array, size);
			}
		} /*End of inner for loop*/
	} /*End of outer for loop*/
}
