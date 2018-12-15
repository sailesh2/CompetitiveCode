#include<iostream>

using namespace std;

int brr[100005];
int save[100005];
void quick(int *,int,int);
int main()
{
    int i,n,k,p,x,y;
    cin>>n>>k>>p;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        brr[i]=i+1;
    }
    quick(arr,0,n-1);
    int ctr=0;
    save[brr[0]]=ctr;
    for(i=1;i<n;i++)
    {
        if((arr[i]-arr[i-1])<=k)
            save[brr[i]]=ctr;
        else
            save[brr[i]]=++ctr;
    }
    for(i=0;i<p;i++)
    {
        cin>>x>>y;
        if(save[x]==save[y])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}


void quick(int *arr,int low,int high)
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
