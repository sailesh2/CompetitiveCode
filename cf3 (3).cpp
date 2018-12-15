#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int n,cnt;
	cin>>n;
	char in[n][n];
	int i,j,crr[200][200];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cin>>in[i][j];
	}
	cnt=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(in[i][j]=='#' && crr[i][j]!=1)
			{
				if(i+1<n && j<n && in[i+1][j]=='#' && crr[i+1][j]!=1)
				crr[i+1][j]=1;
				else
				{
					cnt=1;
					break;
				}
				if(i+1<n && j+1<n && in[i+1][j+1]=='#' && crr[i+1][j+1]!=1)
				crr[i+1][j+1]=1;
				else
				{
					cnt=1;
					break;
				}
				if(i+1<n && j-1<n && in[i+1][j-1]=='#' && crr[i+1][j-1]!=1)
				crr[i+1][j-1]=1;
				else
				{
					cnt=1;
					break;
				}
				if(i+2<n && j<n && in[i+2][j]=='#' && crr[i+2][j]!=1)
				crr[i+2][j]=1;
				else
				{
					cnt=1;
					break;
				}
			}
		}
		if(cnt==1)
		break;
	}
	if(cnt==0)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
