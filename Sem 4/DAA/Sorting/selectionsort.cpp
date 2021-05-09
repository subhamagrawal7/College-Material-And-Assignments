#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
//COUNTING NUMBER OF ELEMENTS IN A FILE
long long count(char file[])
{
	FILE *fp = fopen(file, "r");
	long long count = 0;
	char b[100];
	while (fscanf(fp, "%s\n", &b) == 1)
	{
		count++;
	}

	fclose(fp);
	return count;
}
//Swap function
void swap(long long *xp, long long *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//Selection Sort Function
long long* selectionSort(long long arr[], long long n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}

	return arr;
}
//selection sort function in descending order
long long* selectionSortd(long long arr[], long long n)
{
	int i, j, max_idx;

	for (i = 0; i < n - 1; i++)
	{
		max_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] > arr[max_idx])
				max_idx = j;

		swap(&arr[max_idx], &arr[i]);
	}

	return arr;
}

int main()
{
	clock_t start, end;
	double t;
	int i = 3;
	long long j, *arr, n;
	long long k, temp;
	char filename[15];
	FILE * file;
	for (i = 1; i < 10; i++)
	{
		sprintf(filename, "File %d.txt", i);
		n = count(filename);
		char b[100];
		long long c;
		long j = 0;
		file = fopen(filename, "r");
		arr = (long long *) malloc(n *((long long) sizeof(long long)));
		while (fscanf(file, "%s\n", &b) == 1 && j < n)//taking values into array
		{
			c = atoll(b);
			arr[j] = c;
			j++;
		}

		start = clock();
		arr = selectionSort(arr, n);//average case
		end = clock();
		fclose(file);
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Average case for file %d having %lld elements : %lf\n", i, n, t);
		start = clock();
		arr = selectionSort(arr, n);//best case
		end = clock();
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Best case for file %d having %lld elements : %lf\n", i, n, t);
		start = clock();
		arr = selectionSortd(arr, n);//worst case
		end = clock();
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Worst case for file %d having %lld elements : %lf\n", i, n, t);
		printf("---------------------------------------------------\n");
		free(arr);
	}
}
