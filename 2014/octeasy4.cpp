#include<stdio.h>
#include<iostream>

using namespace std;

void quick(long long int *,int *,int,int);

int main()
{
    int i,n,k=0;
    long long int s,e,a,b;
    long long int arr[1000];
    int brr[1000];
    cin>>n>>s>>e;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        arr[k]=a-b;
        brr[k]=0;
        k++;
        arr[k]=a+b;
        brr[k]=1;
        k++;
    }
    quick(arr,brr,0,k-1);
    long long int f[1000][2],sm=0;
    int l=0,ctr=0,save1,save2,cnt1,cnt2;

    f[0][0]=arr[0];
    for(i=0;i<k;i++)
    {
        if(brr[i]==0)
            ctr=ctr+1;
        else
            ctr=ctr-1;
        if(ctr==0)
        {
                f[l][1]=arr[i];
                l++;
                if(i<k)
                f[l][0]=arr[i+1];

        }
    }
    for(i=0;i<l;i++)
    {
        if(s<f[i][0])
        {
            cnt1=0;
            save1=i;
            break;
        }
        else if(s<f[i][1])
        {
            cnt1=1;
            save1=i;
            break;
        }
    }
    if(i==l)
        cnt1=2;
    for(i=0;i<l;i++)
    {
        if(e<f[i][0])
        {   cnt2=0;
            save2=i;
            break;
        }
        else if(e<f[i][1])
        {
            cnt2=1;
            save2=i;
            break;
        }
    }
    int cnt3=0;
    if(i==l)
        cnt2=2;
    if(cnt2==2)
    {
        if(cnt1==2)
            cout<<e-s;
        else
        {
            for(i=save1;i<l;i++)
        {
            if(i==save1)
            {
                if(cnt1==0)
                    sm=f[i][0]-s;
            }
            else
                sm=sm+f[i][0]-f[i-1][1];
        }
        sm=sm+e-f[l-1][1];
        cout<<sm;
        }
    }
    else
    {
        for(i=save1;i<save2;i++)
        {
            if(i==save1)
            {
                if(cnt1==0)
                    sm=f[i][0]-s;
            }
            else
                sm=sm+f[i][0]-f[i-1][1];
        }
        if(cnt2==0)
            sm=sm+e-f[save2-1][1];
        else
            sm=sm+f[save2][0]-f[save2-1][1];
        cout<<sm;
    }
    return 0;
}
void quick(long long int *arr,int * brr,int low,int high)
{
	int k,ctr1=0,ctr2=0;
	int cnt=1;
	long long int temp;
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

