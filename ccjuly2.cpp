#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    long long int i,t,x,y;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y;
        if(abs(x)>abs(y))
        {
            if(abs(x)%2!=0)
            {
                if(abs(y)%2!=0)
                    cout<<2*abs(x)<<"\n";
                else
                    cout<<2*abs(x)+1<<"\n";
            }
            else
            {
                if(abs(y)%2==0)
                    cout<<2*abs(x)<<"\n";
                else
                    cout<<2*abs(x)+1<<"\n";
            }
        }
        else
        {
            if(abs(y)%2!=0)
            {
                if(abs(x)%2!=0)
                    cout<<2*abs(y)<<"\n";
                else
                    cout<<2*abs(y)+1<<"\n";
            }
            else
            {
                if(abs(x)%2==0)
                    cout<<2*abs(y)<<"\n";
                else
                    cout<<2*abs(y)+1<<"\n";
            }
        }
    }
    return 0;
}
