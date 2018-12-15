#include<stdio.h>
#include<conio.h>

void msort(int,int);
void merge(int,int,int);
int arr[10000];
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	msort(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	getch();
	return 0;
}
void msort(int low,int high)
{
	if(low==high)
	return;
	int mid=(low+high)/2;
	msort(low,mid);
	msort(mid+1,high);
	merge(low,mid,high);
}
void merge(int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int brr[10000],k=0;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			brr[k]=arr[i];
			i++;
			k++;
		}
		else
		{
			brr[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		brr[k]=arr[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		brr[k]=arr[j];
		k++;
		j++;
	}
	for(i=low,j=0;i<=high;i++,j++)
	{
		arr[i]=brr[j];
	}
}
