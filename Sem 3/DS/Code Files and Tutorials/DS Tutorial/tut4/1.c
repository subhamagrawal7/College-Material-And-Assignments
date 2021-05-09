#include<stdio.h>
#include<assert.h>
int main(){
	int n,sum=0,subarray[105],max,i,j;
	scanf("%d",&n);
	assert(n>=1&&n<=105);
	int array[n];
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	j=0;
	for(i=0;i<n;i++){
		if(array[i]>=0){
			sum+=array[i];
			subarray[j]=array[i];
			j++;
		}
	}
	if(j==0){
		max=array[0];
		for(i=0;i<n;i++){
			if(max<array[i]){
				max=array[i];
			}
		}
		subarray[0]=max;
		sum=max;
		j++;
	}
	printf("%d ",sum);
	printf("%d",j);
	return 0;
}

