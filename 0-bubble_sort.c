#include "sort.h"

/**
  * bubble_sort - this sorts an array of ints in ascending order.
  * @array: the array about to be sorted
  * @size: size of the array
  *
  */
void bubble_sort(int *array, size_t size)
{
	int temp;
	unsigned int a, b;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array((const int *)array, size);
			}
		}
	}
}
