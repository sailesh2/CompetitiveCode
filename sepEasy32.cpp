#include<stdio.h>
#include<iostream>

using namespace std;

void quick(int *,int *,int,int);

int main()
{
    int i,t,j,k,n,sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int arr[n][n];
        sm=0;
        int sav[1003]={0};
        for(j=0;j<n;j++)
        {
            int brr[n],crr[n];
            for(k=0;k<n;k++)
            {
                cin>>arr[j][k];
                brr[k]=arr[j][k];
                crr[k]=k;
            }
            quick(brr,crr,0,n-1);
            for(k=n-1;k>=0;k--)
            {
                if(sav[crr[k]]==0)
                    break;
            }
            sav[crr[k]]=1;
            sm=sm+brr[k];
        }
        cout<<sm<<"\n";
    }
    return 0;
}

void quick(int *arr,int *brr,int low,int high)
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

			temp=brr[i];
			brr[i]=brr[p];
			brr[p]=temp;

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

			temp=brr[j];
			brr[j]=brr[p];
			brr[p]=temp;

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
quick(arr,brr,low,p);
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
quick(arr,brr,p+1,high);
}

return;
}
