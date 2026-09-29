#include <stdio.h>

void insertion_sort(int arr[], int N)
{
	for (int i = 1; i < N; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while ( j >= 0 && arr[j] > key)
		{
			arr[ j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int	main (void)
{
	int arr[] = {10, 20, 2, 11, 15, 17, 6};
	int N = sizeof(arr) / sizeof(arr[0]);
	

	printf("====== UNSORTED ARRAY ======\n");

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
printf("\n");
	insertion_sort(arr, N);

	printf("====== SORTED ARRAY ======\n");

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	return (0);
}