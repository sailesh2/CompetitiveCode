#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int i,t,j,p,x,y,u,v;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>p>>x>>y>>u>>v;
        if((u-x+v-y)%2==0)
        {
            if(abs(u-x)==abs(v-y))
            {
            	if(u-x==0)
            	j=0;
            	else
            	j=1;
            }
            else
                j=2;
            if(j<p)
                cout<<"Counter-Terrorists Win !\n";
            else
                cout<<"Terrorists Win !\n";
        }
        else
            cout<<"Terrorists Win !\n";
    }
    return 0;
}
