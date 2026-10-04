#include <stdio.h>
#include <string.h>


int operation_count = 0;   // globalni brojač, ili prosledjen kroz strukturu

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
			operation_count++;
		}

		arr[j + 1] = key;
	}
}

void chunk_sort(int arr[], int len, int num_chunks)
{
	int chunk_size;
	int result[20];
	int position = 0;

	int max_value = arr[0];

	for (int i = 0; i < len; i++)
		{
			if (arr[i] > max_value)
			{
				max_value = arr[i];
			}
		}

	chunk_size = max_value / num_chunks + 1;

	for (int c = 0; c < num_chunks; c++)
	{

		int min = c * chunk_size;
		int max = min + chunk_size - 1;

		int bucket[20];
		int count = 0;

		for (int i = 0; i < len; i++)
		{
			if (min <= arr[i] && arr[i] <= max)
			{
				bucket[count] = arr[i];
				count++;
			}
		}

		insertion_sort(bucket, count);
		for (int k = 0; k < count; k++)
		{
			result[position] = bucket[k];
			position++;
		}
		//printf("%d ", bucket[c]);
	}
	for (int i = 0; i < len; i++)
        arr[i] = result[i];
}

int	main (int argc, char **argv)
{
	int arr[] = {5, 1, 8, 3, 6};
	int num_chunks = 2;
	int len = sizeof(arr) / sizeof(arr[0]);
	int use_counter_flag = 0;


	if (argc > 1 && strcmp(argv[1], "lucas") == 0)
{
    if (use_counter_flag == 1)
    {
        printf("Mistake: flag -c written more then once\n");
        return (1);
    }
    use_counter_flag = 1;
}


	printf("====== UNSORTED ARRAY ======\n");

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
printf("\n");
	chunk_sort(arr, len, num_chunks);

	printf("====== SORTED ARRAY ======\n");

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	if (use_counter_flag)
    printf("Number of all operation is: %d\n", operation_count);

	return (0);
}