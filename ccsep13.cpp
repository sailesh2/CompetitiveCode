#include<stdio.h>
#include<iostream>

using namespace std;

long long int s,p,j,k;
int six[7]={1,6,15,20,15,6,1};
int ans[7]={0};

int main()
{
    int n,i;

    cin>>n;
    n=n-13;
    if(n<0)
        cout<<"0";
    else if(n==0)
        cout<<"1";
    else
    {
        s=1;
        ans[0]=s;
        s=s+six[1]*1;
        ans[1]=s;

        s=s+six[1]*1+six[2]*1;
        ans[2]=s;


        s=s+six[1]*1+six[2]*2+six[3]*1;
        ans[3]=s;


        s=s+six[1]*1+six[2]*3+six[3]*3+six[4]*1;
        ans[4]=s;


        s=s+six[1]*1+six[2]*4+six[3]*6+six[4]*4+six[5]*1;
        ans[5]=s;


        s=s+six[1]*1+six[2]*5+six[3]*10+six[4]*10+six[5]*5+six[6]*1;
        ans[6]=s;
        if(n%2!=0)
            n--;
        n=n/2;
        if(n<=6)
            cout<<ans[n];
        else
        {
            i=1;
            j=n;
            p=1;
            while(i<=6)
            {
                p=p*i;
                k=j/p;
                s=(s+(k-six[i])*six[i]);
                j=j*(n-i);
                i++;
            }
            cout<<s%1000000007;
        }
    }
    return 0;
}
