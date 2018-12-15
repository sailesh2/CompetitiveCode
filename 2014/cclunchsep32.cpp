#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

struct note
{
    int val;
    int flag;
    int ind;
};
struct note narr[100];
void quick(int,int);
int main()
{
    int n,i,m,j,k,a,b,c,d;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cin>>m;
    k=0;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            cin>>d;
            struct note n;
            n.val=b-1;
            n.flag=0;
            n.ind=d;
            narr[k++]=n;


            struct note n1;
            n1.val=c-1;
            n1.flag=1;
            n1.ind=d;
            narr[k++]=n1;
        }
    }
    quick(0,m-1);
    int tw=0,th=0,f=0,sv;
    int twp,thp,fp;
    for(i=0;i<m;i++)
    {
        if(i>0)
        {
            for(j=sv;j<=narr[i].val;j++)
            {
                if(arr[j]%tw==0)
                {
                    twp=(int)floor(math.log(arr[j]));
                    arr[j]=arr[j]/(pow(2,twp));
                }
                if(arr[j]%th==0)
                {
                    thp=(int)math.floor(math.log(arr[j],3));
                    arr[j]=arr[j]/(pow(2,thp));
                }
                if(arr[j]%f==0)
                {
                    fp=(int)math.floor(math.log(arr[j],5));
                    arr[j]=arr[j]/(pow(2,fp));
                }
            }
        }
        if(narr[i].flag==0)
        {
            if(n.ind==2)
                tw++;
            if(n.ind==3)
                th++;
            if(n.ind==5)
                f++;
            sv=narr[i].val;
        }
        else
        {
            if(n.ind==2)
                tw--;
            if(n.ind==3)
                th--;
            if(n.ind==5)
                f--;
            sv=narr[i].val+1;
        }
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
void quick(int low,int high)
{
	int k,ctr1=0,ctr2=0;
	int cnt=1;
	struct note temp;
	int p=(low+high)/2;
	int i=low,j=high;
while(1)
{
 if(cnt==1)
 {
		if(i<p)
		{
		if(narr[i].val>narr[p].val)
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
		if(narr[j].val<narr[p].val)
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
	if(narr[k].val>narr[k+1].val)
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
	if(narr[k].val>narr[k+1].val)
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
