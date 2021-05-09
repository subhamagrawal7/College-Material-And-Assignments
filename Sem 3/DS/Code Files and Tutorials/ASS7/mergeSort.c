//MERGE SORT
#include<stdio.h>
void mergeSort(int a[],int b[],int lb,int ub);
void merge(int a[],int b[],int lb,int mid,int ub);
int main(){
	int n,i;
	printf("Enter the length of unsorted array: ");
	scanf("%d",&n);
	int a[n],b[n];
	printf("Enter the unsorted array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergeSort(a,b,0,n-1);
	printf("The sorted Array (USING MERGE SORTING) is: ");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

void mergeSort(int a[],int b[],int lb,int ub){
	if(lb<ub){
		int mid=(lb+ub)/2;
		mergeSort(a,b,lb,mid);
		mergeSort(a,b,mid+1,ub);
		merge(a,b,lb,mid,ub);
	}
}

void merge(int a[],int b[],int lb,int mid,int ub){
	int i=lb,j=mid+1,k=lb;
	while(i<=mid&&j<=ub){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
		}else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=ub){
			b[k]=a[j];
			k++,j++;
		}
	}else{
		while(i<=mid){
			b[k]=a[i];
			k++,i++;
		}
	}
	for(k=lb;k<=ub;k++){
		a[k]=b[k];
	}
}
