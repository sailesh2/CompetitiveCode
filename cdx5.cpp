#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

void sort(int *,int,int,int *);

int main()
{
	int i,t,j;
	cin>>t;
	cin.ignore();
	for(i=0;i<t;i++)
	{
        int ctr,lt,sum=0,k=0,l=0;
		char sh[150];
		int drr[150];
		int crr[200]={0};
		//cin.ignore();
		cin.getline(sh,150);
//		cout<<sh;
		//cout<<s;
		//cout<<s.length();
		/*for(j=0;j<s.length();j++)
		{
			if(s[j]!=' ')
			{
				sh[l++]=s[j];
			}
		}*/
		/*for(j=0;j<l;j++)
		{
			cout<<sh[j];
		}*/
		//cin.ignore();
		//cout<<"SH"<<sh<<"END"<<endl;
        for(j=0;j<strlen(sh);j++)
		{
			if(sh[j]!=' ')
			{
				if(crr[(int)sh[j]]==0)
				drr[k++]=(int)sh[j];
				crr[(int)sh[j]]++;
			}
		}
		//for(j=0;j<k;j++)
		//<<drr[j];
		sort(drr,0,k-1,crr);
		ctr=0;
		lt=1;
		for(j=0;j<k;j++)
		{
			//cout<<j;
			sum=sum+crr[drr[j]]*(lt+1);
			ctr++;
			if(ctr==lt)
			{
				lt++;
				ctr=0;
			}
		}
		cout<<sum<<"\n";
	}
	getch();
	return 0;
}
void sort(int *arr,int low,int high,int *crr)
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
		if(crr[arr[i]]<crr[arr[p]])
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
		if(crr[arr[j]]>crr[arr[p]])
		{
			temp=arr[j];
			arr[j]=arr[p];
			arr[p]=temp;
			p=j;
			cnt=1;
		}
		if(cnt==0)
		j--;
		if(!(j>p))
		cnt=1;
	    }
	    else
	    cnt=1;
	}
	if(i==p && j==p)
	break;
}
for(k=low;k<p;k++)
{
	if(crr[arr[k]]<crr[arr[k+1]])
	{
		ctr1++;
		break;
	}
}
if(low!=p && ctr1!=0)
{
sort(arr,low,p,crr);
}
for(k=p+1;k<high;k++)
{
	if(crr[arr[k]]<crr[arr[k+1]])
	{
		ctr2++;
		break;
	}
}

if((p+1!=high)&& ctr2!=0)
{
sort(arr,p+1,high,crr);
}

return;
}
