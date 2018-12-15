#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int i,j,k,l;
	for(i=0;i<s.length();i++)
	{
		cout<<s[i]<<"\n";
		for(j=i+1;j<s.length();j++)
		{
			for(k=j;k<s.length();k++)
			{
				cout<<s[i];
				for(l=j;l<=k;l++)
				cout<<s[l];
				cout<<"\n";
			}
		}
	}
	getch();
	return 0;
}
