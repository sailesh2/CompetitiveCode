#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int mis[11][4];
int area[11];
int has[11]={0};
int arr[11];
int ans[11];
float p=1;//pow(11,111);
float maxi=0;

void fun(int,float,int);
int main()
{
    int i,k;
    for(i=1;i<11;i++)
    {
        k=0;
        if(i+1==10)
            mis[i][k++]=10;
        else
            mis[i][k++]=(i+1)%10;
        if(i-1<=0)
            mis[i][k++]=10+(i-1);
        else
            mis[i][k++]=(i-1)%10;
        if(i+3==10)
            mis[i][k++]=10;
        else
            mis[i][k++]=(i+3)%10;
        if(i-3<=0)
            mis[i][k++]=10+(i-3);
        else
            mis[i][k++]=(i-3)%10;
    }
    for(i=1;i<11;i++)
    {
        for(k=0;k<4;k++)
            cout<<mis[i][k]<<" ";
        cout<<"\n";
    }
    for(i=1;i<11;i++)
        cin>>area[i];
    for(i=1;i<11;i++)
    {
        arr[0]=i;
        has[i]=1;
        for(k=1;k<11;k++)
            area[k]=area[k]*p;
        fun(i,1/(float)(area[i]/p),1);
        for(k=1;k<11;k++)
            area[k]=area[k]/p;
        has[i]=0;
    }
    for(i=0;i<10;i++)
        cout<<ans[i]<<" ";
    return 0;
}
void fun(int i,float s,int ctr)
{
   // cout<<"ctr--"<<ctr<<"\n";
    int j,k;
    if(s>=maxi && ctr==10)
    {
     //   cout<<"j";
        for(j=0;j<10;j++)
            {
       //         cout<<arr[j];
                ans[j]=arr[j];
            }
        maxi=s;
    }
    for(j=0;j<4;j++)
    {
        if(has[mis[i][j]]==0)
        {
           // cout<<"as";
            has[mis[i][j]]=1;
            arr[ctr]=mis[i][j];
            for(k=1;k<11;k++)
            area[k]=area[k]*p;
            fun(mis[i][j],s+1/((float)area[mis[i][j]]/p),ctr+1);
            has[mis[i][j]]=0;
            for(k=1;k<11;k++)
            area[k]=area[k]/p;
        }
    }
}
