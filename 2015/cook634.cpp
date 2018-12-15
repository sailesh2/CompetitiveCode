#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n,maxi,val,save,save2,ctr,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        maxi=0;
        int arr[n],mrr[n],crr[n],drr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
            mrr[j]=n+1;
            crr[j]=0;
            drr[j]=0;
        }
        k=0;
        for(j=0;j<n;j++)
        {
            val=arr[j];
            save=-1;
            save2=-1;
            ctr=1;
            //k=0;
            //cout<<k<<"\n";
            while(1)
            {
                while(save+ctr<k && val>arr[mrr[save+ctr]])
                {
                    save2=save+ctr;
                    ctr=ctr*2;
                }
                if(save==save2)
                    break;
                save=save2;
                ctr=1;
            }
            //cout<<save+ctr<<"\n";
            if(save+ctr<k)
            crr[save+ctr]=crr[save+ctr]+(j-mrr[save+ctr]);
            else
                crr[save+ctr]=crr[save+ctr]+1;
            mrr[save+ctr]=j;
            drr[save+ctr]++;
            k=save+ctr+1;
        }
        maxi=0;
        for(j=0;j<n;j++)
        {
            if(mrr[j]!=n+1)
            {
                crr[j]=crr[j]+(drr[j]-1)*(n-mrr[j]-1);
                cout<<j<<" "<<mrr[j]<<" "<<crr[j]<<" "<<drr[j]<<"\n";

               if(j>maxi)
                maxi=j;
            }
        }
        cout<<crr[maxi-1]<<"\n";

    }
    return 0;
}
