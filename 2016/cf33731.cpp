#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,p,ctr,j,num,cnt,n,k;
    cin>>n;
    p=pow(2,n);
    int arr[p][p];
    for(i=0;i<p;i++)
    {
        arr[i][0]=0;
    }
    cnt=0;
    ctr=1;
    num=p/2;
    while(ctr<p)
    {
        for(i=0;i<p;i++)
        {
            k=ctr;
            for(j=0;j<ctr;j++)
            {
                if((cnt/num)%2==0)
                    arr[i][k]=arr[i][j];
                else
                    arr[i][k]=1-arr[i][j];
                k++;
            }
            cnt++;
        }
        ctr=ctr*2;
        num=num/2;
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<p;j++)
        {
            if(arr[i][j]==0)
                cout<<'+';
            else
                cout<<'*';
        }
        cout<<"\n";
    }
    return 0;
}
