
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
clock_t start, end;
double cpu_time_used;
void merge(long long gArray[], long long low, long long mid1, long long mid2, long long high, long long destArray[]) 
{ 
	int i = low, j = mid1, k = mid2, l = low;  
	while ((i < mid1) && (j < mid2) && (k < high)) 
	{ 
		if(gArray[i] < gArray[j]) 
		{ 
			if(gArray[i] < gArray[k]) 
			{ 
				destArray[l++] = gArray[i++]; 
			} 
			else
			{ 
				destArray[l++] = gArray[k++]; 
			} 
		} 
		else
		{ 
			if(gArray[j] < gArray[k]) 
			{ 
				destArray[l++] = gArray[j++]; 
			} 
			else
			{ 
				destArray[l++] = gArray[k++]; 
			} 
		} 
	} 
	while ((i < mid1) && (j < mid2)) 
	{ 
		if(gArray[i] < gArray[j]) 
		{ 
			destArray[l++] = gArray[i++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[j++]; 
		} 
	} 
 
	while ((j < mid2) && (k < high)) 
	{ 
		if(gArray[j] < gArray[k]) 
		{ 
			destArray[l++] = gArray[j++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[k++]; 
		} 
	} 
 
	while ((i < mid1) && (k < high)) 
	{ 
		if(gArray[i] < gArray[k]) 
		{ 
			destArray[l++] = gArray[i++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[k++]; 
		} 
	} 

	while (i < mid1) {
		destArray[l++] = gArray[i++]; 
	}
	while (j < mid2) {
		destArray[l++] = gArray[j++]; 
	}
	while (k < high) {
		destArray[l++] = gArray[k++]; 
	}
} 

void mergeSort3WayRec(long long gArray[], long long low, long long high, long long destArray[]) 
{ 
	if (high - low < 2) {
		return ; 
	}
	int mid1 = low + ((high - low) / 3); 
	int mid2 = low + 2 * ((high - low) / 3) + 1; 
	mergeSort3WayRec(destArray, low, mid1, gArray); 
	mergeSort3WayRec(destArray, mid1, mid2, gArray); 
	mergeSort3WayRec(destArray, mid2, high, gArray); 
	merge(destArray, low, mid1, mid2, high, gArray); 
} 

void mergeSort3Way(long long gArray[], long long n) 
{ 
	if (n == 0) {
		return; 
	}
	long long *fArray;
	fArray=(long long*)malloc(n*(sizeof(long long))); 
	for (int i = 0; i < n; i++) {
		fArray[i] = gArray[i];
	} 
	mergeSort3WayRec(fArray, 0, n, gArray); 
	for (int i = 0; i < n; i++) {
		gArray[i] = fArray[i]; 
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
		mergeSort3Way(arr, n);//average case
		end = clock();
		fclose(file);
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Average case for file %lld having %lld elements : %lf\n", i, n, t);
		/*start = clock();
		mergeSort3Way(arr, n);//best case
		end = clock();
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Best case for file %lld having %lld elements : %lf\n", i, n, t);
		start = clock();
		mergeSort3Way(arr, n);//worst case
		end = clock();
		t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Worst case for file %lld having %lld elements : %lf\n", i, n, t);*/
		printf("///////////////////////////////////////////////////////////////\n");
		free(arr);
	}
}

