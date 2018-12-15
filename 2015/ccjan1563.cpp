#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long long int i,j,n,q,x,y,z;
    long long int sumz,sumo,sumt,sum;
    string str;
    cin>>n>>q;
    long long int arr[n];
    cin>>str;
    for(i=0;i<n;i++)
    {
        arr[i]=(int)str[i]-48;
    }
    for(i=0;i<q;i++)
    {
        cin>>x>>y>>z;
        if(x==1)
        {
            arr[y-1]=z;
        }
        else
        {
            sum=0;
            sumz=0;
            sumo=0;
            sumt=0;
            for(j=y-1;j<z;j++)
            {
                sum=(sum+arr[j])%3;
                if(sum==0)
                    sumz++;
                else if(sum==1)
                    sumo++;
                else
                    sumt++;
            }
            cout<<(sumz*(sumz+1))/2+(sumo*(sumo-1))/2+(sumt+(sumt-1))/2<<"\n";
        }
    }
    return 0;
}
