#include<stdio.h>
//MATRIX CONVERSION
int main()
{
	int n,i,j,sum=0;
	printf("Matrix is of order NXN\nenter N\n");
	scanf("%d",&n);
	if(n<0)
	{
		printf("-ve entry not accepted");
		return 0;
	}
	int arr1[n][n];
	printf("enter integer elements\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr1[i][j]);
		}
	}
	int arr2[n+1][n+1];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr2[i][j]=arr1[i][j];
			sum=sum+arr1[i][j];
		}
		arr2[i][j]=sum;
		sum=0;
	}
	sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=sum+arr1[j][i];
		}
		arr2[j][i]=sum;
		sum=0;
	}
	sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			sum=sum+arr1[i][j];
		}
	}
	arr2[n][n]=sum;
	printf("INPUT--\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
        {

			printf("%d ",arr1[i][j]);
		}
	    printf("\n");
    }
	printf("OUTPUT--\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==n)
			printf("%d",arr2[i][j]);
			else
			printf("%d ",arr2[i][j]);
		}
		printf("\n");
	}

	return 0;
	
	
}
