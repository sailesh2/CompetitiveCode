#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,j,t,p,q,r,ctr,save,start,el;
    long long int sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cin>>p;
        int arr[p];
        for(j=0;j<p;j++)
        {
            cin>>arr[j];
        }
        cin>>q;
        int brr[q];
        for(j=0;j<q;j++)
        {
            cin>>brr[j];
        }
        cin>>r;
        int crr[r];
        for(j=0;j<r;j++)
        {
            cin>>crr[j];
        }

        long long int drr[100005]={0};
        for(j=q-1;j>=0;j--)
        {
            el=brr[j];
            start=j-1;
            save=start;
            ctr=1;
            if((r-1)>=j)
            {
                while((start+ctr)<=r-1)
                {
                    while((start+ctr)<=r-1 && crr[start+ctr]<el)
                    {
                        save=start+ctr;
                        ctr=ctr*2;
                    }
                    if(ctr==1)
                    {
                        start=save;
                        break;
                    }
                    start=save;
                    ctr=1;
                }

            //cout<<start<<"\n";
            drr[j]=(long long int)((r-1)-start);
            }
            else
                drr[j]=(long long int)0;
            if(j!=q-1)
                drr[j]=drr[j]+drr[j+1];
        }
        //for(j=0;j<q;j++)
            //cout<<drr[j]<<" ";
        for(j=0;j<p;j++)
        {
            el=arr[j];
            start=j-1;
            save=start;
            ctr=1;
            if((q-1)>=j)
            {
                while((start+ctr)<=q-1)
                {
                    while((start+ctr)<=q-1 && brr[start+ctr]<el)
                    {
                        save=start+ctr;
                        ctr=ctr*2;
                    }
                    if(ctr==1)
                    {
                        start=save;
                        break;
                    }
                    start=save;
                    ctr=1;
                }
          //      cout<<start<<"\n";
                if(start+1<=q-1)
                    sm=sm+drr[start+1];
            }
        }
        cout<<sm<<"\n";
    }
    return 0;
}
