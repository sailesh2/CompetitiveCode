#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,m,k,t,i,j,temp;
    cin>>n>>m>>k>>t;
    int arr[k+t][3];
    int ans[t];
    for(i=0;i<k;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        arr[i][2]=0;
    }
    for(;i<k+t;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        arr[i][2]=i+1-k;
    }
    for(i=0;i<k+t;i++)
    {
        for(j=i;j<k+t;j++)
        {
            if(arr[j][0]<arr[i][0])
            {
                temp=arr[j][0];
                arr[j][0]=arr[i][0];
                arr[i][0]=temp;


                temp=arr[j][1];
                arr[j][1]=arr[i][1];
                arr[i][1]=temp;


                temp=arr[j][2];
                arr[j][2]=arr[i][2];
                arr[i][2]=temp;
            }
            else if(arr[j][0]==arr[i][0])
            {
                if(arr[j][1]<arr[i][1])
                {
                    temp=arr[j][0];
                arr[j][0]=arr[i][0];
                arr[i][0]=temp;


                temp=arr[j][1];
                arr[j][1]=arr[i][1];
                arr[i][1]=temp;


                temp=arr[j][2];
                arr[j][2]=arr[i][2];
                arr[i][2]=temp;
                }
            }
            else
            {

            }
        }
    }
    int ctr=0,a;
    for(i=0;i<k+t;i++)
    {
        if(arr[i][2]!=0)
        {
            int cnt=0;
            for(j=0;j<k+t;j++)
            {
                if(arr[j][2]==0 && arr[j][0]==arr[i][0] && arr[j][1]==arr[i][1])
                {
                    cnt=2;
                    break;
                }
            }
            if(cnt==2)
            {
                   ans[arr[i][2]-1]=-1;
            }
            else
            {
                ans[arr[i][2]-1]=((arr[i][0]-1)*m+arr[i][1]-ctr)%3;
            }
        }
        else
            ctr++;
    }
    for(i=0;i<t;i++)
    {
        if(ans[i]==-1)
            cout<<"Waste\n";
        else if(ans[i]==1)
            cout<<"Carrots\n";
        else if(ans[i]==2)
            cout<<"Kiwis\n";
        else
            cout<<"Grapes\n";
    }
    return 0;
}
