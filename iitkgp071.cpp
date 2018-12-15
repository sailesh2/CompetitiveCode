#include<stdio.h>
#include<iostream>

using namespace std;

int arr[10]={0};
int ans[2000]={0};
int ind;
void fun(int,int);
void quick(int,int);
int main()
{
    int i,t,x,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x;
        ind=0;
        for(j=0;j<x;j++)
            arr[j]=j+1;
        fun(0,x-1);
        quick(0,ind-1);
        for(j=0;j<ind;j++)
            cout<<ans[j]<<" ";
        cout<<"\n";
    }
    return 0;
}
void fun(int i,int j)
{
    int temp,k,s=0;
    if(i==j)
    {
        for(k=0;k<=j;k++)
        {
            s=s*10+arr[k];
        }
        ans[ind++]=s;
        return;
    }
    for(k=i;k<=j;k++)
    {
        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;

        fun(i+1,j);

        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
}
void quick(int low,int high)
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
		if(ans[i]>ans[p])
		{
			temp=ans[i];
			ans[i]=ans[p];
			ans[p]=temp;
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
		if(ans[j]<ans[p])
		{
			temp=ans[j];
			ans[j]=ans[p];
			ans[p]=temp;
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
	if(ans[k]>ans[k+1])
	{
		ctr1++;
		break;
	}
}
if(low!=p && ctr1!=0)
{
quick(low,p);
}
for(k=p+1;k<high;k++)
{
	if(ans[k]>ans[k+1])
	{
		ctr2++;
		break;
	}
}

if((p+1!=high)&& ctr2!=0)
{
quick(p+1,high);
}

return;
}
