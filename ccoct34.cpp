#include<stdio.h>
#include<iostream>

using namespace std;


int main()
{
    int i,t,j,n,m,save,maxi;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        int val;
        int save;
        char x;
        char cols;
        long long int p=1;
        maxi=0;
        for(j=0;j<m;j++)
        {
            cin>>x>>val;
            if(val>=maxi)
                maxi=val;
            arr[j]=val;
            counter[val]=(int)x;
        }
        for(j=0;j<m;j++)
        {
            if(counter[i]!=0)
                ctr=ctr+1;
        }

        cout<<p<<"\n";
    }
    return 0;
}
