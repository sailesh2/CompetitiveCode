#include<stdio.h>
#include<conio.h>

int main()
{
	int i,j,temp,n;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(arr[j]<arr[j-1])
			{
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	getch();
	return 0;
}
