#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

struct node
{
	int val;
	int var;
};
struct node arr[100][100];
void sort(struct node *,int,int);
int main()
{
	int v,e,i,j,k,a,b,value;
    cout<<"enter no. of vertices\n";
	cin>>v;
	cout<<"enter no of edges\n";
	cin>>e;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		arr[i][j].val=1000;
	}
	for(i=0;i<e;i++)
	{
		cin>>a>>b>>value;
		arr[a][b].val=value;
		arr[a][b].var=b;
		arr[b][a].val=value;
		arr[b][a].var=a;
	}
	for(i=0;i<v;i++)
	sort(arr[i],0,v-1);
	int crr[100]={0};
	crr[0]=1;
	int chk[0]=1;
	for(i=0;i<v;i++)
	{
		cnt=0;
		if(chk[i]==1)
		{
			if(arr[crr[i]].val!=1000)
			{
				if(chk[arr[crr[i]].var]==1)
				{
					while(chk[arr[crr[i]].val]==1)
					{
						if(arr[crr[i]].val==1000)
						{
							cnt=1;
							break;
						}
						crr[i]++;
					}
					if(cnt==0)
					{
						if(arr[crr[i]].val<=mini)
						{
							mini=arr[crr[i]].val;
							save1=i;
							save2=arr[crr[i]].var;
						}
					}
				}
				else
				{
                    	if(arr[crr[i]].val<=mini)
						{
							mini=arr[crr[i]].val;
							save1=i;
							save2=arr[crr[i]].var;
						}

				}
			}
		}
		cout<<save1<<"--"<<save2<<"\n";
		crr[arr[save1]]++;
		chk[save2]=1;
	}
	getch();
	return 0;
}
void sort(struct node *arr,int low,int high)
{
	int k,ctr1=0,ctr2=0;
	int cnt=1;
	struct node temp;
	int p=(low+high)/2;
	int i=low,j=high;
while(1)
{
 if(cnt==1)
 {
		if(i<p)
		{
		if(arr[i].val>arr[p].val)
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
		if(arr[j].val<arr[p].val)
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
	if(arr[k].val>arr[k+1].val)
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
	if(arr[k].val>arr[k+1].val)
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
