#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n;
    long long int a,b,gcd,temp;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        long long int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        if(n==1)
            cout<<arr[0]<<"\n";
        else
        {
            a=arr[0];
            b=arr[1];
            if(a>b)
            {
                while(1)
                {
                    if(a%b==0)
                    {
                        gcd=b;
                        break;
                    }
                    temp=a;
                    a=b;
                    b=temp%b;
                }
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

            for(j=2;j<n;j++)
            {
                a=gcd;
                b=arr[j];
                if(a>b)
                {
                    while(1)
                    {
                        if(a%b==0)
                        {
                            gcd=b;
                            break;
                        }
                        temp=a;
                        a=b;
                        b=temp%b;
                    }
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
            cout<<gcd*n<<"\n";
        }
    }
    return 0;
}
