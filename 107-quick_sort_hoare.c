#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - tgis swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Ordering a subset of an array of integers
 *                   according to the partition scheme.
 * @array:  array of integers.
 * @size:  size of the array.
 * @left:  starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int focus, above, below;

	focus = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < focus);
		do {
			below--;
		} while (array[below] > focus);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - this implement the quicksort algorithm through recursion.
 * @array: this is an array of integers to sort.
 * @size:  size of the array.
 * @left:  starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int pt;

	if (right - left > 0)
	{
		pt = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, pt - 1);
		hoare_sort(array, size, pt, right);
	}
}

/**
 * quick_sort_hoare - Sorting an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
