#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int mini1,mini2,n,m;
int row[10][10],col[10][10],crr[10][10];
void fun(int,int,int,int,int);
int main()
{
  int i,j;
  cin>>m>>n;
  for(i=0;i<m;i++)
    {
    for(j=0;j<n-1;j++)
      {
      cin>>row[i][j];
    }
  }
  for(i=0;i<m-1;i++)
    {
    for(j=0;j<n;j++)
      {
      cin>>col[i][j];
    }
  }
  for(i=0;i<10;i++)
    {
    for(j=0;j<10;j++)
      crr[i][j]=0;
  }
  mini1=100000;
  mini2=100000;
  crr[0][0]=1;
  fun(1,0,1,1,row[0][0]);
  fun(2,1,0,1,col[0][0]);
  if(mini1<=mini2)
    {
    if(mini1<100000)
      cout<<mini1<<"\n";
    else
      cout<<"0\n";
  }
   else
    {
    if(mini2<100000)
      cout<<mini2<<"\n";
    else
      cout<<"0\n";
  }
  getch();
  return 0;
}
void fun(int which,int x,int y,int ctr,int sum)
  {
	if(ctr==(m*n)-1)
    {
	 if(which==1)
      {
      if(x==1 && y==0)
        {
        if(sum<=mini1)
          mini1=sum+col[0][0];
      }
    }

    if(which==2)
      {
      if(x==0 && y==1)
        {
        if(sum<=mini2)
          mini2=sum+row[0][0];
      }
    }
  }
  crr[x][y]=1;
  if(x>=0 && x<m && y<n-1 && y>=0)
  {
    if(crr[x][y+1]==0)
  	{
      fun(which,x,y+1,ctr+1,sum+row[x][y]);
    }
  }

  if(x>=0 && x<m && y>0 && y<n)
  {
    if(crr[x][y-1]==0)
  	{
	  fun(which,x,y-1,ctr+1,sum+row[x][y-1]);
    }
  }
  if(x>=0 && x<m-1 && y<n && y>=0)
  {
    if(crr[x+1][y]==0)
  	{
      fun(which,x+1,y,ctr+1,sum+col[x][y]);
    }
  }
  if(x>0 && x<m && y<n && y>=0)
  {
    if(crr[x-1][y]==0)
  	{
      fun(which,x-1,y,ctr+1,sum+col[x-1][y]);
    }
}
crr[x][y]=0;
  return;
}
