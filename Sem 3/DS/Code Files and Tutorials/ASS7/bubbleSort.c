//BUBBLE SORT
#include<stdio.h>
void bubbleSort(int A[],int n);
int main(){
	int n,i;
	printf("Enter the length of unsorted array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the unsorted array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubbleSort(a,n);
	return 0;
}
//*****BUBBLE SORT FUNCTION**********//
void bubbleSort(int A[],int n){
	int i,j,flag,temp;
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-1-i;j++){
			if(A[j]>A[j+1]){
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				flag=1;	
			}
		}
		if(flag==0){
			break;
		}
	}
	printf("The sorted Array (USING BUBBLE SORTING) is: ");
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
}
