#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

int top=-1;
char stack[1000000];
void push(char);
char pop();
int main()
{
	char a;
	int i,t,j,sm,cnt;
	cin>>t;
	string s;
	for(i=0;i<t;i++)
	{
		top=-1;
		cin>>s;
		cnt=0;
		sm=0;
		for(j=0;j<s.length();j++)
		{
			if(s[j]=='<')
			{
				push(s[j]);
				cnt++;
			}
			else
			{
				a=pop();
				if(a=='F')
				break;
			}
			if(top==-1)
			{
				sm=sm+cnt*2;
				cnt=0;
			}
		}
		cout<<sm<<"\n";
	}
	getch();
	return 0;
}
void push(char c)
{
	stack[++top]=c;
}
char pop()
{
	if(top==-1)
	return 'F';
	return stack[top--];
}
