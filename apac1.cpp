#include<stdio.h>
#include<iostream>

using namespace std;

int s;
int arr[1005][1005];
int sav[1005][1005];
int fun(int,int,int);

int main()
{
    int i,t,j,k,a,maxi,ans;
    cin>>t;
    for(i=0;i<t;i++)
    {
        maxi=0;
        cin>>s;
        for(j=0;j<s;j++)
        {
            for(k=0;k<s;k++)
            {
                sav[j][k]=-1;
                cin>>arr[j][k];
            }
        }
        for(j=0;j<s;j++)
        {
            for(k=0;k<s;k++)
            {
      //          cout<<"\n";
                a=fun(j,k,arr[j][k]);
            }
        }



      /*  for(j=0;j<s;j++)
        {
            for(k=0;k<s;k++)
                cout<<sav[j][k]<<" ";
        }*/
        for(j=0;j<s;j++)
        {
            for(k=0;k<s;k++)
            {
                if(sav[j][k]==maxi)
                {
                    if(arr[j][k]<ans)
                    {
                        ans=arr[j][k];
                    }
                }
                if(sav[j][k]>maxi)
                {
                    maxi=sav[j][k];
                    ans=arr[j][k];
                }
            }
        }
        cout<<"Case #"<<i+1<<": "<<ans<<" "<<maxi+1<<"\n";
    }
    return 0;
}
int fun(int i,int j,int sm)
{
    //cout<<i<<" - "<<j<<"\n";
    if(i>=s || j>=s || i<0 || j<0)
        return -1;
    if(arr[i][j]<sm)
        return -1;
    if(arr[i][j]-sm>1)
        return -1;
    if(sav[i][j]!=-1)
        return sav[i][j];
    int one=fun(i,j+1,arr[i][j])+1;
    int two=fun(i+1,j,arr[i][j])+1;
    int maxm;
    if(one>two)
        maxm=one;
    else
        maxm=two;
    if(i-1>=0 && arr[i-1][j]==arr[i][j]+1)
    {
        if(sav[i-1][j]+1>maxm)
            maxm=sav[i-1][j]+1;
    }
    if(j-1>=0 && arr[i][j-1]==arr[i][j]+1)
    {
        if(sav[i][j-1]+1>maxm)
            maxm=sav[i][j-1]+1;
    }
    sav[i][j]=maxm;
     //cout<<"s--i,j-"<<i<<" "<<j<<" "<<sav[i][j]<<"\n";

    if(i+1<s && arr[i+1][j]+1==arr[i][j])
    {
        //cout<<"sav--i+1,j"<<sav[i+1][j]<<"\n";
        if(sav[i][j]+1>sav[i+1][j])
            sav[i+1][j]=sav[i][j]+1;
    }

    if(j+1<s && arr[i][j+1]+1==arr[i][j])
    {
        //cout<<"sav--i,j+1"<<sav[i][j+1]<<"\n";
        if(sav[i][j]+1>sav[i][j+1])
            sav[i][j+1]=sav[i][j]+1;
    }

    return sav[i][j];
}
