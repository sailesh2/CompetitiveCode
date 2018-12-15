#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,j;
    long long int sm,n1;
    string n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        cout<<n<<"\n";
        sm=0;
        for(j=0;j<n.length();j++)
        {
            sm=sm+int(n[j])-48;
        }
        if(sm/10==0)
        {
            cout<<"dg\n";
            if(sm==0)
                cout<<"9\n";
            else
                cout<<sm<<"\n";
        }
        else
        {
            n1=sm;
            sm=0;
            while(1)
            {
                while(n1!=0)
                {
                    sm=sm+n1%10;
                    n1=n1/10;
                }
                if(sm/10==0)
                    break;
                cout<<sm<<"\n";
                n1=sm;
                sm=0;
            }
        cout<<"asf\n";
        if(sm==0)
            cout<<"9\n";
        else
            cout<<sm<<"\n";
        }
    }
    return 0;
}
