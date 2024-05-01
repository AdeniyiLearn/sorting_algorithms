#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * @array: an integer array
 * @size: the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int temp, demo, temp_check;
	size_t i, j;

	temp = '\0';
	temp_check = -1;
	for (i = 0; i < size; i++)
	{
		demo = *(array + i);
		for (j = i + 1; j < size; j++)
		{
			if (demo > *(array + j))
			{
				demo = array[j];
				temp = j;
			}
		} /*End of inner for loop*/
		*(array + temp) = *(array + i);
		*(array + i) = demo;
		if (temp_check != temp)
		{
			print_array(array, size);
			temp_check = temp;
		}
	} /*End of outer for loop*/
}
