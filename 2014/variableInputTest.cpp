#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    int i,ctr=0;
    string s;
    getline(cin,s);
    cout<<s[0]<<s[1]<<s[2];
    /*while(scanf("%d",&i))
    {
        if(i=='\n')
        break;
        ctr++;
        cout<<ctr<<"----"<<i<<"\n";
    }*/
    return 0;
}
