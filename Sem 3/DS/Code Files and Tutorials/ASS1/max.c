#include<stdio.h>
int main()
{
 int a[100],i,n,max;

 printf("Enter size of the array : ");
 scanf("%d",&n);
 printf("Enter elements in array : ");
 for(i=0; i<n; i++)
 {
 	scanf("%d",&a[i]);
 }
 max=a[0];
 for(i=1; i<n; i++)
 {
	if(max<a[i])
 		max=a[i];
 }
 printf("Maximum element of array is : %d",max);
 return 0;
}

