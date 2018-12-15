#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <String.h>

using namespace std;
int maxi;
int len;
string s,p;
void fun(int,int,int);
int main()
{
	maxi=0;
	cin>>s;
	len=s.size();
	cin>>p;
    fun(0,0,0);
cout<<maxi;
    getch();
    return 0;
}
void fun(int j,int save,int ctr)
{
    int a,k;
    if(ctr>=maxi)
        maxi=ctr;
for(k=j;k<len;k++)
{
a=p.find(s.at(k),save);
if(a!=string::npos)
{
fun(k+1,a+1,ctr+1);
}
}
}
