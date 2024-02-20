#include "sort.h"

/**
 * swap - This functions swaps the values of two variables
 * @n: The first variable
 * @m: The second variable
 * Return: void.
 */
void swap(int *n, int *m)
{
	int temp = *n;
	*n = *m;
	*m = temp;
}

/**
 * bubble_sort - This function implements the bubble sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 * Return: void.
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int swapped;

	for (x = 0; x < size - 1; x++)
	{
		swapped = 0;
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				swap(&array[y], &array[y + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
