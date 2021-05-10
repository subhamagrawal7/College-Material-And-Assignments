#include<stdio.h>
void main()
{
 int arr[20],n,i,j,k,l;
 printf("enter the number of elements\n");
 scanf("%d",&n);
 printf("enter the elements \n");
 for(i=0;i<n;i++)
{ scanf("%d",&arr[i]);
}
printf("enter the position to be deletd");
scanf("%d",&l);
printf("enter the element to be deleted\n");
scanf("%d",&k);
if(arr[l-1]==k)
{  for(j=l-1;j<n-1;j++)
{  arr[j]=arr[j+1];
}
for(i=0;i<n-1;i++)
{
printf("%d	",arr[i]);
}
}
else
{printf("the number is not present at that position\n");
}
}
