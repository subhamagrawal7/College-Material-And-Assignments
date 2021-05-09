#include <stdio.h>
int main()
{
 int a[100],i,n,min;

 printf("Enter size of the array : ");
 scanf("%d",&n);
 printf("Enter elements in array : ");
 for(i=0; i<n; i++)
 {
 	scanf("%d",&a[i]);
 }
 min=a[0];
 for(i=1; i<n; i++)
 {
 	if(min>a[i])
 		min=a[i];
 }
 printf("minimum of array is : %d",min);
 return 0;
}

