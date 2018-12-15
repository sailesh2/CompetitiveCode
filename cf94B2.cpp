#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,a,b;
    cin>>t;
    int arr[6][6]={0};
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int cnt=0;
    for(i=1;i<=5;i++)
    {
        for(a=i+1;a<=5;a++)
        {
            for(b=a+1;b<=5;b++)
            {
                if((arr[i][a]==1 && arr[i][b]==1 && arr[a][b]==1) || (arr[i][a]==0 && arr[i][b]==0 && arr[a][b]==0))
                {
                    cnt=1;
                    break;
                }
            }
        }
    }
    if(cnt==1)
        cout<<"WIN\n";
    else
        cout<<"FAIL\n";
    return 0;
}
