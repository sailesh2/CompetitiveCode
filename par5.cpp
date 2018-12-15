#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int arr[10000001]={0};
int main()
{
    int i,q,ctr=0;
    long long int a,b,p;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>a>>b;
        if(a==0)
        {
            ctr++;
            p=1;
            while(p<=b)
            {
                arr[b/p]++;
                p=p*2;
            }
        }
        else if(a==1)
        {
            ctr--;
            p=1;
            while(p<=b)
            {
                arr[b/p]--;
                p=p*2;
            }
        }
        else
        {
            if(b==0)
                cout<<ctr<<"\n";
            else
                cout<<arr[b]<<"\n";
        }
    }
    return 0;
}
