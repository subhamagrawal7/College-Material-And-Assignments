#include<stdio.h>
void sort(int *p,int n)
{int i,var,j;
 for(i=0;i<n;i++)
 {   for(j=i + 1;j<n;j++)
	{if(*(p+i)>*(p+j))
		{var=*(p+i);
		 *(p+i)=*(p+j);
		 *(p+j)=var;
		}
	}
 }
}

void main()
{
 int arr[20],n,i,*p;
 printf("enter the number of elements\n");
 scanf("%d",&n);
 printf("enter the elements \n");
 p=arr;
 for(i=0;i<n;i++)
{ scanf("%d",&arr[i]);
}
sort(p,n);
printf("The maximum element is %d\n",p[n-1]);
printf("The minimum element is %d\n",p[0]);
}

