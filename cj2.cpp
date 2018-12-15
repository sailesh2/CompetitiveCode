#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int i,t;
	long long int n,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		cout<<"Case #"<<i+1<<": ";
		x=(long long int)floor(pow(3+sqrt(5),n));
		cout<<x;
		x=x%1000;
		if(x/10==0)
		cout<<"00";
		if(x/100==0)
		cout<<"0";
		cout<<x%1000<<"\n";
	}
	getch();
	return 0;
}
