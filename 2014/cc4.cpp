#include<stdio.h>
#include<iostream>

using namespace std;

void fun(int,int,int * brr);
int maxi=0;
int m;
int arr[20][20000];
int crr[20];
int main()
{
	int i,j,n,k;
	cin>>n>>m;

int brr[20001]={0};
	for(i=0;i<m;i++)
	{
		cin>>k;
		crr[i]=k;
		for(j=0;j<k;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<crr[i];j++)
		brr[arr[i][j]]=1;
		fun(i,1,brr);
		for(j=0;j<crr[i];j++)
		brr[arr[i][j]]=0;
	}
	cout<<maxi;
	return 0;
}


void fun(int i,int ctr,int *brr)
{
	if(ctr>=maxi)
	maxi=ctr;
	int j,k,cnt;
	for(j=i+1;j<m;j++)
	{
		cnt=0;
		for(k=0;k<crr[j];k++)
		{
			if(brr[arr[j][k]]==1)
			{
				cnt=1;
				break;
			}
		}
		if(cnt==0)
		{
            for(k=0;k<crr[j];k++)
			brr[arr[j][k]]=1;
	
			fun(j,ctr+1,brr);

            for(k=0;k<crr[j];k++)
            brr[arr[j][k]]=0;
    	}
    	if((ctr+m-j-1)<=maxi)
		break;
	}
}
