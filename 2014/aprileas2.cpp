#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long int n;
void quick(long long int *,long long int,long long int);
int main()
{
	long long int i,t,j,x,y,a,b,k1,k2,ctra,ctrb;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a>>b>>n;
		k1=a;
		k2=b;
		ctra=0;
		ctrb=0;
		long long int arr[1000]={0};
		for(j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		sort(arr,arr+n);
		for(j=0;j<n;j++)
		{
			if(arr[j]<=a)
			{
				a=a-arr[j];
				ctra++;
			}
			if(arr[j]<=b)
			{
				b=b-arr[j];
				ctrb++;
			}
		}
		if(ctra>ctrb)
		cout<<"Raghu Won\n";
		else if(ctra<ctrb)
		cout<<"Sayan Won\n";
		else
		cout<<"Tie\n";
	}
	return 0;
}
void quick(long long int *arr,long long int low,long long int high)
{
	int ctr1=0,ctr2=0;
	int cnt=1;
	long long int k,temp;
	long long int p=(low+high)/2;
	long long int i=low,j=high;
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
quick(arr,low,p);
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
quick(arr,p+1,high);
}

return;
}
