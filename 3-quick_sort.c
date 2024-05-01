#include "sort.h"

/**
 * change_values - swaps two values given.
 * @a: first value to swap
 * @b: the second value.
 * Return: nothing.
 */
void change_values(int *a, int *b)
{
	int tmp_item = *a;
	*a = *b;
	*b = tmp_item;
}

/**
 * quick_partion_set - rearrange elements in an array around a pivot element.
 * It uses lomuto partitioning scheme.
 * @array: array to sort
 * @size: size of the array.
 * @low_b: elements in the left side of the pivot.
 * @upper_b: elements in the right side of the pivot element.
 * Return: Number representing the upper bound position of the previous
 * sort.
 */
int quick_partion_set(int *array, int size,  int low_b, int upper_b)
{
	int pivot = upper_b, start = low_b, start_next = low_b;

	while (start_next < upper_b)
	{
		if (array[start_next] < array[pivot])
		{
			if (start < start_next)
			{
				change_values(&array[start_next], &array[start]);
				print_array(array, size);
			}
			start++;
		}
		start_next++;
	}
	if (array[start] > array[pivot])
	{
		change_values(&array[start], &array[pivot]);
		print_array(array, size);
	}
	return (start);
}


/**
 * quick_sort_set1 - recursively calls itself till all elements are
 * sorted.
 * @array: the array to sort
 * @size: size of array.
 * @left: items in the left side of the pivot.
 * @upper: elements in the right side of the pivot element.
 * Return: Number representing the upper bound position of the previous
 * sort.
 */
void quick_sort_set1(int *array, int size, int left, int upper)
{
	int n;

	if (left < upper)
	{
		n = quick_partion_set(array, size, left, upper);
		quick_sort_set1(array, size, left, n - 1);
		quick_sort_set1(array, size, n + 1, upper);
	}
}


/**
 * quick_sort - sorts array of integers in ascending order
 * with the use Quick sort
 * @array: array to be sorted
 * @size: size of the array.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	quick_sort_set1(array, size, 0, size - 1);
}
