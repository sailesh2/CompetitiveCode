#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,n,m,j,ctr,x,maxi,cl,save,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        int arr[401][401]={0};
        int crr[401]={0};
        int in[401],st[401];
        int has[401]={0};
        for(j=0;j<m;j++)
        {
            cin>>x;
            arr[x][crr[x]]=j+1;
            in[j]=x;
            crr[x]++;
        }
        for(j=0;j<m;j++)
        {
            arr[in[j]][crr[in[j]]]=10000;
        }
        for(j=0;j<=400;j++)
            crr[j]=0;
        ctr=0;
        cl=0;
        for(j=0;j<m;j++)
        {
            x=in[j];
            if(ctr==n)
            {
                if(has[x]==1)
                {
                    crr[x]++;
                }
                else
                {
                    has[x]=1;
                    crr[x]++;
                    cl++;
                    maxi=0;
                    for(k=0;k<n;k++)
                    {
                        if(arr[st[k]][crr[st[k]]]>=maxi)
                        {
                            maxi=arr[st[k]][crr[st[k]]];
                            save=k;
                        }
                    }
                    has[st[save]]=0;
                    st[save]=x;
                }
            }
            else
            {
                if(has[x]==0)
                {
                    st[ctr]=x;
                    has[x]=1;
                    ctr++;
                    cl++;
                }
                crr[x]++;
            }
        }
        cout<<cl<<"\n";
    }
    return 0;
}
