#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<map>
#define gc getchar

using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int i,t,j,n,x,cnt,temp,save;
    cin>>t;
    for(i=0;i<t;i++)
    {
        scanint(n);
        int arr[n];
        cnt=0;
        for(j=0;j<n;j++)
        {
            scanint(x);
            arr[j]=x;
           // has.insert(make_pair(x,j));
        }
        save=-1;
        for(j=1;j<n;j++)
        {
            if(arr[j]<arr[j-1])
            {
                if(arr[j-1]==save)
                {
                    cnt=1;
                    break;
                }

                save=arr[j-1];

                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;


                if(j-1!=0 && arr[j-1]<arr[j-2])
                {
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
