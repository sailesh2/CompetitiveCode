#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,t,j,cnt,ctr;
    long long int n;
    cin>>t;
    for(j=0;j<t;j++)
    {
        cin>>n;
        cnt=0;
        ctr=0;
        while (n%2 == 0)
        {
            if(ctr>2)
            {
                cnt=1;
                break;
            }
            ctr++;
            n = n/2;
        }

        for (i = 3; i <= sqrt(n); i = i+2)
        {
            while (n%i == 0)
            {
                printf("%d ", i);
                ctr++;
                n = n/i;
            }
            if(ctr>2)
            {
                cnt=1;
                break;
            }
        }
        if (n > 2)
        {
            ctr++;
            if(ctr>2)
                cnt=1;
        }
        cout<<ctr<<"\n";
        cout<<cnt<<"\n";

        if(cnt==0)
        {
            if(n==1 || ctr<2)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}

