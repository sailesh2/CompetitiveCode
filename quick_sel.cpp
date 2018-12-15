#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int n;

int quick(int [],int,int,int);
int main()
{
	int ans;
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	ans=quick(arr,0,n-1,5);
		for(i=0;i<n;i++)
		{
			printf("%d",arr[i]);
		}
		cout<<ans;
	getch();
	return 0;
}
int quick(int arr[],int low,int high,int check)
{
	int ans,k,ctr1=0,ctr2=0;
	int cnt=1;
	int temp;
	int p=(low+high)/2;
	int i=low,j=high;
while(1)
{
 if(cnt==1)
 {
		if(i<p)
		{
		if(arr[i]>arr[p])
		{
			temp=arr[i];
			arr[i]=arr[p];
			arr[p]=temp;
			p=i;
			cnt=0;
		}
		if(cnt==1)
		i++;
	    }
	    else
	    cnt=0;
}
else
	{
		if(j>p)
		{
		if(arr[j]<arr[p])
		{
			temp=arr[j];
			arr[j]=arr[p];
			arr[p]=temp;
			p=j;
			cnt=1;
		}
		if(cnt==0)
		j--;
		//if(!(j>p))
		//cnt=1;
	    }
	    else
	    cnt=1;
	}
	if(i==p && j==p)
	break;
}
if(p+1-low==check)
return arr[p];
else if(p+1-low<check)
ans=quick(arr,p+1,high,check-(p+1-low));
else
ans=quick(arr,low,p,check);
return ans;
}
