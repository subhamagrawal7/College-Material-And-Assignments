#include<stdio.h>
int main()
{
	int m[3][3];
	int i=0,j=0;
	printf("Enter the elements of the array: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
	//[1][1] sub matrix
	printf("All the [1][1] sub matrices:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("[%d] \n",m[i][j]);
		}
	}
	printf("All the [2][2] sub matrices:\n");
	int l=0,k=0;
	for(l=0;l<2;l++)
	{
		for(k=0;k<2;k++)
		{
			for(i=l;i<l+2;i++)
			{
				for(j=k;j<k+2;j++)
				{
					printf("%d ",m[i][j]);
				}
				printf("\n");
			}
			printf("----------\n");
		}
	}
	printf("Addition of first and second [2][2] matrices: \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			m[i][j]=m[i][j]+m[i][j+1];
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}
