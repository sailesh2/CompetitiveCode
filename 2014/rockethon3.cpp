#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int n,i,j,m;
	cin>>n>>m;
	long long int arr[n][3],brr[m][3],a,b,c,d,min,mino=0;
	for(i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	for(i=0;i<m;i++)
	{
		cin>>brr[i][0]>>brr[i][1]>>brr[i][2];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(arr[i][0]>=brr[j][0] && arr[i][0]<=(brr[j][0]+brr[j][2]) && brr[j][1]>=arr[i][1] && brr[j][1]<=(arr[i][1]+arr[i][2]))
			{
				a=abs(arr[i][0]-brr[j][0]);
				b=abs(arr[i][0]-(brr[j][0]+brr[j][2]));
				c=abs(brr[j][1]-arr[i][1]);
				d=abs(brr[j][1]-(arr[i][1]+arr[i][2]));

				if(a<=b && a<=c && a<=d)
				min=a;
				if(b<=a && b<=c && b<=d)
				min=b;
				if(c<=a && c<=b && c<=d)
				min=c;
				if(d<=a && d<=b && d<=c)
				min=d;
				if(min>=mino)
				mino=min;
			}
		}
	}
	cout<<mino;
	return 0;
}
