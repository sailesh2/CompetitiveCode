#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{
	int i,n,m,a;
	cin>>n>>m;
	int c=0;
	for(i=0;i<n;i++)
	{
		cin>>a;
		c=c+a;
	}
	cout<<(int)ceil((float)abs(c)/m);
	return 0;
}
