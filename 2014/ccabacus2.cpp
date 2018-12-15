#include<stdio.h>
#include<iostream>

using namespace std;

int r,c;
int arr[22][22];
void fun(int,int);
int main()
{
	int i,t,j,n,l,k,x,y;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>r>>c;
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				cin>>arr[j][k];
			}
		}
		cin>>n;
		for(l=0;l<n;l++)
		{
			cin>>x>>y;
			fun(x,y);
		}
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			cout<<arr[j][k]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
void fun(int x,int y)
{
	if(x>=r || y>=c)
	return;
	if(x<0 || y<0)
	return;
	arr[x][y]++;
	if(arr[x][y]>3)
	{
		arr[x][y]=0;
		fun(x-1,y);
		fun(x,y-1);
		fun(x+1,y);
		fun(x,y+1);
	}
}
