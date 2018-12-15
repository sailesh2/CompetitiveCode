#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,d,n,k,a,j,l,p,q,r,s,val,sum;
    char stat;
    cin>>d;
    for(i=0;i<d;i++)
    {
        cin>>n>>k;
        cin>>a;
        int arr[n][n];
        for(j=0;j<n;j++)
        {
            for(l=0;l<n;l++)
            {
                arr[j][l]=k;
            }
        }
        int cuml[n][n];
        for(j=0;j<n;j++)
        {
            for(l=0;l<n;l++)
            {
                if(j==0 && l>0)
                    cuml[j][l]=(arr[j][l]+cuml[j][l-1])%1000000007;
                else if(l==0 && j>0)
                    cuml[j][l]=(arr[j][l]+cuml[j-1][l])%1000000007;
                else if(j==0 && l==0)
                    cuml[j][l]=(arr[j][l])%1000000007;
                else
                {
                    cuml[j][l]=(arr[j][l]+cuml[j][l-1]+cuml[j-1][l]-cuml[j-1][l-1])%1000000007;
                    if(cuml[j][l]<0)
                        cuml[j][l]=cuml[j][l]+1000000007;
                }
            }
        }
        for(j=0;j<a;j++)
        {
            cin>>stat;

            if(stat=='m')
            {
                cin>>p>>q>>r>>s;
                p--;
                q--;
                r--;
                s--;
                if(p==0 && q>0)
                {
                    sum=(cuml[r][s]-cuml[r][q-1])%1000000007;
                       if(sum<0)
                        sum=sum+1000000007;

                }
                else if(q==0 && p>0)
                {
                    sum=(cuml[r][s]-cuml[p-1][s])%1000000007;
                    if(sum<0)
                        sum=sum+1000000007;
                }
                else if(p==0 && q==0)
                {
                    sum=cuml[r][s]%1000000007;
                    if(sum<0)
                        sum=sum+1000000007;
                }
                else
                {
                    sum=(cuml[r][s]-cuml[r][q-1]-cuml[p-1][s]+cuml[p-1][q-1])%1000000007;
                    if(sum<0)
                        sum=sum+1000000007;
                }
                cout<<sum<<"\n";
            }
            else
            {
                cin>>p>>q>>val;
                arr[p-1][q-1]=arr[p-1][q-1]*val;
                for(r=0;r<n;r++)
                {
                    for(s=0;s<n;s++)
                    {
                        if(r==0 && s>0)
                            cuml[r][s]=(arr[r][s]+cuml[r][s-1])%1000000007;
                        else if(r==0 && s>0)
                            cuml[r][s]=(arr[r][s]+cuml[r-1][s])%1000000007;
                        else if(r==0 && s==0)
                            cuml[r][s]=(arr[r][s])%1000000007;
                        else
                        {
                            cuml[r][s]=(arr[r][s]+cuml[r][s-1]+cuml[r-1][s]-cuml[r-1][s-1])%1000000007;
                            if(cuml[r][s]<0)
                                cuml[r][s]=cuml[r][s]+1000000007;
                        }
                    }
                }
            }
        }
    }
}
