#include<iostream>
#include<conio.h>

using namespace std;

char arr[50][50];
int save[50][50];
int mini,n;
void fun(int,int,int);

int main()
{
	int i,j,savesi,savesj;
	mini=100000;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]=='S')
			{
				savesi=i;
				savesj=j;
			}
			save[i][j]=0;
		}
	}
	fun(savesi,savesj,0);
	cout<<mini;
	getch();
	return 0;
}
void fun(int i,int j,int ctr)
{
	save[i][j]=1;
	if(arr[i][j]=='T')
	return;
	if(arr[i][j]=='E')
	{
		if(ctr<=mini)
		mini=ctr;
		return;
	}
	if(i+1<n)
	{
		if(save[i+1][j]==0)
		fun(i+1,j,ctr+1);
	}

	if(j+1<n)
	{
		if(save[i][j+1]==0)
		fun(i,j+1,ctr+1);
	}

	if(i-1>=0)
	{
		if(save[i-1][j]==0)
		fun(i-1,j,ctr+1);
	}

	if(j-1>=0)
	{
		if(save[i][j-1]==0)
		fun(i,j-1,ctr+1);
	}
}
