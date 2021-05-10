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
printf("enter the position to be inserted\n");
scanf("%d",&l);
printf("enter the element to be inserted\n");
scanf("%d",&k);
for(j=n;j>l-1;j--)
{
  arr[j]=arr[j-1];
}
arr[l-1]=k;
printf("The array data is \n");
for(i=0;i<=n;i++)
{printf("%d\t",arr[i]);
}
}
