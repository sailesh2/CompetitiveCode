#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,r,g,b,m,maxir,maxib,maxig,x,j,maxi,mini;
    cin>>t;
    for(i=0;i<t;i++)
    {
        maxi=0;
        maxir=0;
        maxig=0;
        maxib=0;
        cin>>r>>g>>b>>m;
        for(j=0;j<r;j++)
        {
            cin>>x;
            if(x>=maxir)
                maxir=x;
        }
        for(j=0;j<g;j++)
        {
            cin>>x;
            if(x>=maxig)
                maxig=x;
        }
        for(j=0;j<b;j++)
        {
            cin>>x;
            if(x>=maxib)
                maxib=x;
        }
            if(maxir>=maxib && maxir>=maxig)
                maxi=maxir;
            else if(maxib>=maxir && maxib>=maxig)
                maxi=maxib;
            else
                maxi=maxig;
            mini=maxi;
        for(j=0;j<m;j++)
        {
            if(maxir>=maxib && maxir>=maxig)
            {
                maxir=maxir/2;
            }
            else if(maxib>=maxir && maxib>=maxig)
            {
                maxib=maxib/2;
            }
            else
            {
                maxig=maxig/2;
            }
            if(maxir>=maxib && maxir>=maxig)
                maxi=maxir;
            else if(maxib>=maxir && maxib>=maxig)
                maxi=maxib;
            else
                maxi=maxig;
            if(maxi<=mini)
                mini=maxi;
        }
        cout<<mini<<"\n";
    }
    return 0;
}
