#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,n,h,s,m,d,j,gcd,a,b,temp,lt,hr,mn,sc;
    double p,sm,lb,ub;
    int arr[17]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    cin>>n;
    lt=17;
    i=0;
    while(i<n)
    {
        cin>>hr>>mn>>sc;
        sm=0;
        j=0;
        while(j<lt)
        {
            h=hr;
            m=mn;
            s=sc;
            p=1;

                if(h%arr[j]==0 && m%arr[j]==0)
                    p=1;
                else
                    p=0;

                lb=arr[j]*(ceil((float)1/arr[j]));
                ub=arr[j]*(floor((float)59/arr[j]));
                p=p*((ub-lb)/arr[j]+1);
                //cout<<p<<"\n";

                sm=sm+(int)p;

                if(h%arr[j]==0)
                    p=1;
                else
                    p=0;

                lb=arr[j]*(ceil((float)(m+1)/arr[j]));
                ub=arr[j]*(floor((float)(59)/arr[j]));
                p=p*((ub-lb)/arr[j]+1);

                lb=arr[j]*(ceil((float)1/arr[j]));
                ub=arr[j]*(floor((float)59/arr[j]));
                p=p*((ub-lb)/arr[j]+1);
                //cout<<p<<"\n";

                sm=sm+(int)p;


                p=1;
                lb=arr[j]*(ceil((float)(h+1)/arr[j]));
                ub=arr[j]*(floor((float)23/arr[j]));
                p=p*((ub-lb)/arr[j]+1);

                lb=arr[j]*(ceil((float)1/arr[j]));
                ub=arr[j]*(floor((float)(59)/arr[j]));
                p=p*((ub-lb)/arr[j]+1);

                lb=arr[j]*(ceil((float)1/arr[j]));
                ub=arr[j]*(floor((float)59/arr[j]));
                p=p*((ub-lb)/arr[j]+1);
                //cout<<p<<"\n";

                sm=sm+(int)p;
            j=j+1;
        }
        d=(60-sc)+60*(59-mn)+60*60*(23-hr)-sm;
        a=sm;
        b=d;
        gcd=1;
        if(a>0 && b>0)
        {
            if(a>b)
            {
                while(1)
                {
                    if(a%b==0)
                        gcd=b;
                        break;
                }
                    temp=a;
                    a=b;
                    b=temp%b;
            }
            else
            {
                while(1)
                {
                    if(b%a==0)
                    {
                        gcd=a;
                        break;
                    }
                    temp=b;
                    b=a;
                    a=temp%a;
                }
            }
        }
        cout<<sm/gcd<<":"<<d/gcd<<"\n";
        i=i+1;
    }
    return 0;
}
