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
//LINEAR SEARCH FUNCTION
long long search(long long arr[], long long n, long long x)
{
	long long i;
	for (i = 0; i <= n; i++)
		if (arr[i] == x)
			return x;
	return -1;
}

int main()
{
	int i;
	long long j;
	long long * arr;
	long long n;
	char filename[15];
	char storefile[20];
	FILE * file;
	sprintf(filename, "File 1.txt");
	n = count(filename);
	char e[100];
	long long f;
	file = fopen(filename, "r");
	arr = (long long *) malloc(n *((long long) sizeof(long long)));
	while (fscanf(file, "%s\n", &e) == 1 && j < n)
	{
		f = atoll(e);
		arr[j] = f;
		j++;
	}

	//COMPILE TIME CALCULATION
	long long c = 121548;	//element present in the file for best case
	start = clock();
	printf("Element: %d\n", search(arr, n, c));
	end = clock();
	fclose(file);
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;//BEST CASE
	printf("Best case for file %d having %lld elements : %0.10lf\n", i + 1, n, cpu_time_used);
	printf("///////////////////////////////////////////////////////////////////////////\n");
	long long b = 1234567;	//number not in file for worst case
	start = clock();
	printf("Element: %d\n", search(arr, n, b));
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;//WORST CASE
	printf("Worst case for file %d having %lld elements : %0.10lf\n", i + 1, n, cpu_time_used);
	printf("///////////////////////////////////////////////////////////////////////////\n");
	free(arr);
}
