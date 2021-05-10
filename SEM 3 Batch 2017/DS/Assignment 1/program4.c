#include<stdio.h>
void main()
{
 int arr[30],n,i,j,k,l;
 printf("enter the number of elements\n");
 scanf("%d",&n);
 printf("enter the elements \n");
 for(i=0;i<n;i++)
{ scanf("%d",&arr[i]);
}
printf("enter the position to be deleted\n");
scanf("%d",&l);
printf("Current array data is\n");
for(j=l-1;j<n;j++)
{
  arr[j]=arr[j+1];
}

for(i=0;i<n-1;i++)
{printf("%d\t",arr[i]);
}
}
