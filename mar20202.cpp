#include<stdio.h>
#include<math.h>
#include<iostream>
#include<conio.h>

using namespace std;

int di;
int fun1(int *,int,int);
int orig[3];
int main()
{
	int k,i,j,t,cnt;
	long long int n;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		k=0;
		if(n==0)
		cout<<"YES\n";
		else
		{
      	di=(int)floor(log10(n))+1;
      	if(di==1)
		{
			if(n%8==0)
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
		else if(di==2)
		{
			if(n%8==0)
			cout<<"YES\n";
			else
			{
				if(((n%10*10)+n/10)%8==0)
				cout<<"YES\n";
				else
				cout<<"NO\n";
			}
		}
		else
		{
			int arr[di];
			while(n>0)
			{
			arr[di-k-1]=n%10;
				n=n/10;
				k++;
			}
          
            if(fun1(arr,0,0)==1)
              cout<<"YES\n";
            else
			cout<<"NO\n";
		}
		}
	}
	getch();
	return 0;
}
int fun1(int *arr,int i,int ctr)
{
	if(ctr==3)
	{
		if((orig[0]*100+orig[1]*10+orig[2])%8==0)
		return 1;
		if((orig[0]*100+orig[2]*10+orig[1])%8==0)
		return 1;
		if((orig[1]*100+orig[0]*10+orig[2])%8==0)
		return 1;
		if((orig[1]*100+orig[2]*10+orig[0])%8==0)
		return 1;
		if((orig[2]*100+orig[0]*10+orig[1])%8==0)
		return 1;
		if((orig[2]*100+orig[1]*10+orig[0])%8==0)
		return 1;
		return 0;
	}
	int a,j;
	for(j=i;j<di;j++)
	{
		orig[ctr]=arr[j];
		a=fun1(arr,j+1,ctr+1);
		if(a==1)
		return 1;
	}
	return 0;
}
