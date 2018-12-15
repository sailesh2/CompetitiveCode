#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,ctra=0,ctrb=0,cntra,cntrb,cntrsa,cntrsb,t,s,j;
    cin>>n;
    int arr[n];
    int ans[10][2];
    int k=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
            ctra++;
        else
            ctrb++;
    }
    if(arr[n-1]==1)
    {
    for(i=1;i*i<=ctra;i++)
    {
        if(ctra%i==0)
        {
            t=i;
            s=ctra/i;
            cntra=0;
            cntrb=0;
            cntrsa=0;
            cntrsb=0;
            for(j=0;j<n;j++)
            {
                if(arr[j]==1)
                    cntra++;
                else
                    cntrb++;
                if(cntra==t || cntrb==t)
                {
                    if(cntra==t)
                    cntrsa++;
                    else
                    cntrsb++;
                    cntra=0;
                    cntrb=0;
                }
            }
            if(cntrsa==s && cntrsb<s && cntra==0 && cntrb==0)
            {
                ans[k][0]=s;
                ans[k][1]=t;
                k++;
            }
            if(s!=t)
            {
                s=i;
                t=ctra/i;
                cntra=0;
                cntrb=0;
                cntrsa=0;
                cntrsb=0;
                for(j=0;j<n;j++)
                {
                    if(arr[j]==1)
                        cntra++;
                    else
                        cntrb++;
                    if(cntra==t || cntrb==t)
                    {
                        if(cntra==t)
                        cntrsa++;
                        else
                        cntrsb++;
                        cntra=0;
                        cntrb=0;
                    }
                }
                if(cntrsa==s && cntrsb<s && cntra==0 && cntrb==0)
                {
                    ans[k][0]=s;
                    ans[k][1]=t;
                    k++;
                }
            }
        }
    }
    }
    else
    {
    for(i=1;i*i<=ctrb;i++)
    {
        if(ctra%i==0)
        {
            t=i;
            s=ctrb/i;
            cntra=0;
            cntrb=0;
            cntrsa=0;
            cntrsb=0;
            for(j=0;j<n;j++)
            {
                if(arr[j]==2)
                    cntrb++;
                else
                    cntra++;
                if(cntrb==t || cntra==t)
                {
                    if(cntrb==t)
                    cntrsb++;
                    else
                    cntrsa++;
                    cntra=0;
                    cntrb=0;
                }
            }
            if(cntrsb==s && cntrsa<s && cntrb==0 && cntra==0)
            {
                ans[k][0]=s;
                ans[k][1]=t;
                k++;
            }
            if(s!=t)
            {
                s=i;
                t=ctrb/i;
                cntra=0;
                cntrb=0;
                cntrsa=0;
                cntrsb=0;
                for(j=0;j<n;j++)
                {
                    if(arr[j]==2)
                        cntrb++;
                    else
                        cntra++;
                    if(cntrb==t || cntra==t)
                    {
                        if(cntrb==t)
                        cntrsb++;
                        else
                        cntrsa++;
                        cntra=0;
                        cntrb=0;
                    }
                }
                if(cntrsb==s && cntrsa<s && cntrb==0 && cntra==0)
                {
                    ans[k][0]=s;
                    ans[k][1]=t;
                    k++;
                }
            }
        }
    }
    }
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(ans[i][0]>ans[j][0])
            {
                ctra=ans[i][0];
                ans[i][0]=ans[j][0];
                ans[j][0]=ctra;

                ctra=ans[i][1];
                ans[i][1]=ans[j][1];
                ans[j][1]=ctra;
            }
            else if(ans[i][0]==ans[j][0])
            {
                if(ans[i][1]>ans[j][1])
                {
                    ctra=ans[i][1];
                    ans[i][1]=ans[j][1];
                    ans[j][1]=ctra;
                }
            }
        }
    }
    cout<<k<<"\n";
    for(i=0;i<k;i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
    return 0;
}
