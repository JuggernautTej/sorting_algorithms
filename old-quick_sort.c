#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - performs the Lomuto partition
 * @arr: an arrays of integers
 * @low: the index of the first element of the partition
 * @high: the index of the last element in the partition
 * Return: An integer representing the index where
 *	the pivot element should be placed after sorting
 */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; /* Pivot is the last element */
	int i = (low - 1), j; /* Initialize left index */

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]); /* Swap pivot to its correct position */
	return (i + 1);
}

/**
 * quick_sort_recursive - implements the quick sort algorithm with the Lomuto
 * @arr: array of integers
 * @low: index of the first element of the partition
 * @high: the index of the last element of the partition
 * Return: void
 */
void quick_sort_recursive(int arr[], int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high);

		quick_sort_recursive(arr, low, pi - 1);
		quick_sort_recursive(arr, pi + 1, high);
	}
}

/**
 * quick_sort - the actual quick sort function
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
/**
 * array_print - prints array
 * @arr: an array of integers
 * @size: size of the array
 * Return: void
 */
void array_print(int arr[], size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}
