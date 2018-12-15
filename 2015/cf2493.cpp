#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    int sm=0,cnt=-1,maxi=0,mini=10000000,j,k,ctr,sm2=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        cnt=cnt*-1;
        sm=sm+cnt*arr[i];
        sm2=sm2+arr[i];
        if(sm>maxi)
            maxi=sm;
        if(sm<mini)
            mini=sm;
    }
    mini=min(0,mini);
    maxi=max(0,maxi);
    //cout<<maxi<<" "<<mini<<"\n\n";
    char brr[maxi-mini+1][sm2];
    cnt=0;
    j=-1*mini;
    k=0;
    for(i=0;i<n;i++)
    {
        ctr=0;
        if(cnt==0)
        {
            while(ctr<arr[i])
            {
                brr[j][k]='/';
                //cout<<j<<" "<<k<<"\n";
                k++;
                ctr++;
                if(ctr<arr[i])
                    j++;
            }
        }
        else
        {
            while(ctr<arr[i])
            {
                brr[j][k]='\\';
                //cout<<j<<" "<<k<<"\n";
                k++;
                ctr++;
                if(ctr<arr[i])
                    j--;
            }
        }
        cnt=1-cnt;
    }
    for(i=maxi-mini-1;i>=0;i--)
    {
        for(j=0;j<sm2;j++)
        {
            if(brr[i][j]=='/')
                cout<<"/";
            else if(brr[i][j]=='\\')
                cout<<"\\";
            else
                cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
