#include <stdio.h>
int main()
{
 int a[100],i,n,min,second_min;

 printf("Enter size of the array : ");
 scanf("%d",&n);
 printf("Enter elements in array : ");
 for(i=0; i<n; i++)
 {
 	scanf("%d",&a[i]);
 }
 min=a[0];
 second_min=a[0];
 for(i=1; i<n; i++)
 {
 	if(min>a[i]){
 		second_min=min;
 		min=a[i];
	 }
 }
 printf("Second minimum element of array is : %d",second_min);
 return 0;
}

