#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t;
    long long int x,y,gcd,temp;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y;
        if(x>=y)
        {
            while(1)
            {
                if(x%y==0)
                {
                    gcd=y;
                    break;
                }
                temp=x;
                x=y;
                y=temp%y;
            }
        }
        else
        {
            while(1)
            {
                if(y%x==0)
                {
                    gcd=x;
                    break;
                }
                temp=y;
                y=x;
                x=temp%x;
            }
        }
        cout<<gcd<<"\n";
    }
    return 0;
}
