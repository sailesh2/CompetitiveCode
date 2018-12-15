#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    long long int i,n,l,r,d,a,b,p1,p,cnt,d1,d2;
    cin>>n;
    cin>>l>>r;
    d=int(floor(log10(n)))+1;
    p=pow(10,d-1);
    cnt=0;
    while(p!=0)
    {
        a=n/p;
        b=n%p;
        cout<<a<<"\n";
        if(a%l==0 && b%r==0 && a!=0 && b!=0)
        {
            cnt=1;
            cout<<"YES"<<"\n";
            d1=int(floor(log10(a)))+1;
            d2=int(floor(log10(b)))+1;
            cout<<a*pow(10,d-d1-d2)<<"\n";
            cout<<b<<"\n";
            break;
        }
        p=p/10;
    }
    if(cnt==0)
        cout<<"NO";
    return 0;
}
