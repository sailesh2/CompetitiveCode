#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i=3,ctr=1;
    int arr[100000],brr[100000];
    arr[0]=2;
    brr[0]=0;
    brr[1]=0;
    brr[2]=2;
    int s=2,cnt,j,k=1;
    while(i<1000)
    {
        cnt=0;
        if(i%2!=0)
        {
            j=0;
            while(j<ctr and arr[j]<=pow(i,0.5))
            {
                if(i%arr[j]==0)
                {
                    cnt=1;
                    break;
                }
                j=j+1;
            }
            if(cnt==0)
            {
                arr[k++]=i;
                s=s+i;
                ctr++;
            }
        }
        brr[i]=s;
        i=i+1;
    }
    int t,a,b;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        cout<<brr[b]-brr[a-1]<<"\n";
    }
    return 0;
}
