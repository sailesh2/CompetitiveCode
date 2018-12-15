#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,j,n,m,mini,t,k;
    cin>>t;
    for(k=0;k<t;k++)
    {
        string x,y;
        cin>>x>>y;
        int ins,d,r,kg,savei,savej;
        cin>>ins>>r>>kg;
        d=ins;

        if(ins==0 || r==0)
            cout<<"0\n";
        else
        {
            n=x.length();
            m=y.length();
            int arr[1000][1000];
            for(i=0;i<n+1;i++)
            {
                if(d*i>kg)
                    break;
                arr[i][0]=d*i;
            }
            for(j=0;j<m+1;j++)
            {
                if(ins*j>kg)
                    break;
                arr[0][j]=ins*j;
            }
            savei=i;
            savej=j;
            if(savei<=1 && savej<=1)
                cout<<"-1\n";
            else
            {
            if(savei<=0 || savej<=0)
                cout<<"-1\n";
            else
            {
            for(i=1;i<savei;i++)
            {
                for(j=1;j<savej;j++)
                {
                    mini=arr[i-1][j]+d;
                    if(arr[i][j-1]+ins<=mini)
                    {
                        mini=arr[i][j-1]+ins;
                    }
                    if(x[i]==y[j])
                    {
                        if(arr[i-1][j-1]<=mini)
                            mini=arr[i-1][j-1];
                    }
                    else
                    {
                        if(arr[i-1][j-1]+r<=mini)
                        {
                            mini=arr[i-1][j-1]+r;
                        }
                    }
                    arr[i][j]=mini;
                }
            }
            if((savei-1>=0 && savei-1<=n) && ((savej-1>=0 && savej-1<=m) ))
            cout<<arr[savei-1][savej-1]<<"\n";
            else
                cout<<"-1\n";
            }
            }
        }
    }
    return 0;
}
