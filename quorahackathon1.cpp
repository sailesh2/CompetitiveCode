#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace  std;

int main()
{
    int i,n,m,ist,save,save1,ctr;
    long long int x1,y1,x2,y2,sm=0;
    cin>>n;
    long long int arr[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]=arr[i]*arr[i];
    }
    sort(arr+1,arr+n+1);
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        x1=x1*x1;
        y1=y1*y1;
        x2=x2*x2;
        y2=y2*y2;
        save=0;
        save1=0;
        while(1)
        {
            save=save1;
           // cout<<save<<"\n";
            ctr=1;
            while(1)
            {
                if(save+ctr>n || ((x1+y1-arr[save+ctr])>0 && (x2+y2-arr[save+ctr])<0) || ((x1+y1-arr[save+ctr])<0 && (x2+y2-arr[save+ctr])>0))
                    break;
                if( (x1+y1-arr[save+ctr])<0 && (x2+y2-arr[save+ctr])<0 )
                    break;
         //       cout<<(x1+y1-arr[save+ctr])<<"  "<<(x2+y2-arr[save+ctr])<<"\n";
                save1=save+ctr;
                ctr=ctr*2;
            }
            if(save==save1)
                break;
        }
        ist=save;
        if(ist>n)
            ist=n;
        //cout<<ist<<" ";
        while(1)
        {
            save=save1;
            ctr=1;
            while(1)
            {
                if(save+ctr>n || ((x1+y1-arr[save+ctr])<0 && (x2+y2-arr[save+ctr])<0) )
                    break;
                save1=save+ctr;
                ctr=ctr*2;
            }
            if(save==save1)
                break;
        }
        if(save>n)
            save=n;
        //cout<<save<<"\n";
        if(save>=ist)
            sm=sm+save-ist;
            //cout<<save-ist<<"\n";
    }
    cout<<sm<<"\n";
}
