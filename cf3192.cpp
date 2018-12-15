#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,j,n2,n,ctr;
    cin>>n2;
    int arr[1000]={0};
    for(j=1;j<=n2;j++)
    {
        n=j;
        //cout<<n<<"\n";
        ctr=2;
        while (n%2 == 0)
        {
            arr[ctr]=1;
            n = n/2;
            ctr=ctr*2;
        }

        for (i = 3; i*i <= n; i = i+2)
        {
            ctr=i;
            while (n%i == 0)
            {
                arr[ctr]=1;
                n = n/i;
                ctr=ctr*i;
            }
        }

        if (n > 2)
            arr[n]=1;
    }
    ctr=0;
    for(i=1;i<=n2;i++)
    {
        if(arr[i]==1)
            ctr++;
    }
    cout<<ctr<<"\n";
    for(i=1;i<=n2;i++)
    {
        if(arr[i]==1)
            cout<<i<<" ";
    }
    return 0;
}
