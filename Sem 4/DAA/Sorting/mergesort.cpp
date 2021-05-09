
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(long long arr[], long long l, long long m, long long r)
{
    long long i;
	long long j;
	long long k;
    long long n1 = m - l + 1;
    long long n2 = r - m;

    /* create temp arrays */
    long long *left;
    long long *right;
    left=(long long*)malloc(n1*(sizeof(long long)));
	right=(long long*)malloc(n2*(sizeof(long long)));

 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */ 
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
 

void mergeSort(long long arr[], long long l, long long r)
{
    if (l < r) {

        long long m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
long long count(char file[]) {
  FILE * fp = fopen(file, "r");
  long long count = 0;
  char b[100];
  while (fscanf(fp, "%s\n", & b) == 1) {
    count++;
  }

  fclose(fp);
  return count;
} 
int main()
{
	clock_t start, end;
	double t;
	int i = 3;
	long long j = 0, *arr, n;
	long long k, temp;
	char filename[15];
	FILE * file;
	for (i = 1; i <= 10; i++)
	{
		sprintf(filename, "File %d.txt", i);
		n = count(filename);
		char b[100];
		long long c;
		file = fopen(filename, "r");
		arr = (long long *) malloc(n *((long long) sizeof(long long)));
		while (fscanf(file, "%s\n", &b) == 1 && j < n)//taking values into array
		{
			c = atoll(b);
			arr[j] = c;
			j++;
		}

		start = clock();
		mergeSort(arr, 0,n- 1);
		end = clock();
		fclose(file);
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Average case for file %lld having %lld elements : %lf\n", i, n, t);
		/*start = clock();
		bubbleSort(arr, n);//best case
		end = clock();
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Best case for file %lld having %lld elements : %lf\n", i, n, t);
		start = clock();
		bubbleSortdsc(arr, n);//worst case
		end = clock();
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Worst case for file %lld having %lld elements : %lf\n", i, n, t);
	*/
		printf("///////////////////////////////////////////////////////////////\n");
		free(arr);
	}
	return 0;
}

