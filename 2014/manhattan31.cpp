#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,j,k;
    cin>>t;
    int n,m,a,s,p,l,f;
    string str;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        int arr[n];
        for(j=0;j<n;j++)
        {
            s=0;
            cin>>str;
            for(k=0;k<m;k++)
            {
                s=s*2+int(str[k])-48;
            }
            arr[j]=s;
        }
        p=1;

        int cnt=1;
        for(k=0;k<m;k++)
        {
            int sav[1000]={0};
            cnt=0;
            for(j=0;j<n;j++)
            {
                l=arr[j]%p;
                f=arr[j]/(p*2);
                if(sav[l*p+f]==1)
                {
                    cnt=1;
                    break;
                }
                sav[l*p+f]=1;
            }
            if(cnt==0)
            {
                cout<<"YES\n";
                break;
            }
            p=p*2;
        }
        if(cnt==1)
            cout<<"NO\n";
    }
    return 0;
}
