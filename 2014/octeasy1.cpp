#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,m,q,i,j,save,save1,ctr,a,mini;
    cin>>n>>m>>q;
    int arr[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin>>arr[i][j];
    }

    for(i=0;i<q;i++)
    {
        mini=10000000;
        for(j=0;j<n;j++)
        {
            cin>>a;
            save=-1;
            ctr=1;
            while(save+ctr<m)
            {
                if(a>=arr[j][save+ctr])
                {
                    save1=save+ctr;
                    ctr=ctr*2;
                }
                else
                {
                    if(ctr==1)
                        break;
                    save=save1;
                    ctr=1;
                }
                if(save+ctr>=m)
                {
                    ctr=1;
                    save=save1;
                }
            }
            //cout<<save+1<<"\n";
            if(save+1<=mini)
                mini=save+1;
        }
        cout<<mini<<"\n";
    }
    return 0;
}
