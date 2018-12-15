#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,k,t,j,n,mini,maxi,cnt;
    cin>>t;
    for(k=0;k<t;k++)
    {
        cin>>n;
        int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        cout<<"Case #"<<k+1<<": ";
        if(n==1)
            cout<<"yes\n";
        else
        {
            mini=arr[0];
            maxi=arr[0];
            i=1;
            j=n-1;
            cnt=0;
            while(i<=j)
            {
                if(arr[i]==mini-1)
                {
                    i++;
                    mini--;
                }
                else if(arr[i]==maxi+1)
                {
                    i++;
                    maxi++;
                }
                else if(arr[j]==mini-1)
                {
                    j--;
                    mini--;
                }
                else  if(arr[j]==maxi+1)
                {
                    j--;
                    maxi++;
                }
                else
                {
                    cnt=1;
                    break;
                }
            }
            if(cnt==1)
                cout<<"no\n";
            else
                cout<<"yes\n";
        }
    }
    return 0;
}
