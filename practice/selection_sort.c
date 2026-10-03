#include <stdio.h>

void selection_sort(int arr[], int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		int min_idx = i;

		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		
		}
		//this was mistake, i left it inside of the loop, 
		// so i was swapping so many times inside jloop 
		// 
		int tmp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = tmp;	
		
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
	selection_sort(arr, N);

	printf("====== SORTED ARRAY ======\n");

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return (0);
}