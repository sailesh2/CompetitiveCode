#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,x,y,l,k,j,cnt,ctr;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y>>k;
        int arr[x+y];
        for(j=0;j<x;j++)
            arr[j]=0;
        while(j<y)
        {
            arr[j]=1;
            j++;
        }
        l=0;
        while(l<k)
        {
        j=x+y-1;
        cnt=0;
        ctr=0;
        while(j>=0)
        {
            if(arr[j]==0)
            {
                if(cnt==1)
                    break;
            }
            else
            {
                ctr++;
                cnt=1;
                arr[j]=0;
            }
            j--;
        }
        arr[j]=1;
        ctr--;
        j=x+y-1;
        while(ctr>0)
        {
            arr[j]=1;
            j--;
            ctr--;
        }
        l++;
        }
        for(j=0;j<x+y;j++)
        {
            if(arr[j]==1)
                cout<<"V";
            else
                cout<<"H";
        }
        cout<<"\n";
    }
    return 0;
}
