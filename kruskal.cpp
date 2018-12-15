#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;
int chk[100][100],ctr[100],crr[100];
void sort(int *,int,int);
int fun(int,int,int);
int main()
{
	int v,e,i,j,k;
	cout<<"enter no. of vertices\n";
	cin>>v;
	cout<<"enter no of edges\n";
	cin>>e;
	int brr[e][2],drr[e];
	int x,y,val,a;
	for(i=0;i<e;i++)
	{
		cout<<"enter\n";
		cin>>x>>y>>val;
		brr[i][0]=x;
		brr[i][1]=y;
		crr[i]=i;
		drr[i]=val;
 	}
	sort(drr,0,e-1);
	for(i=0;i<e;i++)
	{
		x=brr[crr[i]][0];
		y=brr[crr[i]][1];
		a=x;
		int cnt=0;
		for(j=0;j<ctr[a];j++)
		{
			cnt=fun(chk[a][j],a,y);
		}
		if(cnt==0)
		{
			chk[x][ctr[x]]=y;
			ctr[x]++;
			chk[y][ctr[y]]=x;
			ctr[y]++;
			cout<<x<<"--"<<y<<"\n";
		}
	}
	getch();
	return 0;
}
int fun(int a,int b,int y)
{
	int i,cnt=0;
	for(i=0;i<ctr[a];i++)
	{
		if(chk[a][i]!=b)
		{
			if(chk[a][i]==y)
			{
				cnt=1;
				break;
			}
			cnt=fun(chk[a][i],a,y);
			if(cnt==1)
			break;
		}
	}
	return cnt;
}
void sort(int *arr,int low,int high)
{
	int k,ctr1=0,ctr2=0;
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
			
			temp=crr[i];
			crr[i]=crr[p];
			crr[p]=temp;

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
			
			temp=crr[j];
			crr[j]=crr[p];
			crr[p]=temp;

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
for(k=low;k<p;k++)
{
	if(arr[k]>arr[k+1])
	{
		ctr1++;
		break;
	}
}
if(low!=p && ctr1!=0)
{
sort(arr,low,p);
}
for(k=p+1;k<high;k++)
{
	if(arr[k]>arr[k+1])
	{
		ctr2++;
		break;
	}
}

if((p+1!=high)&& ctr2!=0)
{
sort(arr,p+1,high);
}

return;
}
