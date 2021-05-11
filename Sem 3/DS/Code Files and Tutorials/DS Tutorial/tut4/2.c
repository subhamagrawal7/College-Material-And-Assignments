#include<stdio.h>
#include<assert.h>
int main(){
	int n,i,j,k=0,max;
	scanf("%d",&n);
	assert(n>=1&&n<=105);
	int a1[n],a2[n],mad[n*n];
	for(i=0;i<n;i++){
		scanf("%d",&a1[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&a2[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a2[j]>=a1[i]&&j>=i){
				mad[k]=j-i;
				k++;
			}else{
				mad[k]=0;
				k++;
			}
		}
	}
	max=mad[0];
	for(i=0;i<k;i++){
		if(mad[i]>max){
			max=mad[i];
		}
	}
	printf("%d",max);
}
