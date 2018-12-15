#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int i,t,j,n,val,ctr,save,save2;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        vector<int> v;
        v.push_back(arr[0]);
        for(j=1;j<n;j++)
        {
            val=arr[j];
            ctr=1;
            save=-1;
            save2=-1;
            while(1)
            {
                while(save+ctr<v.size() && v[save+ctr]<=val)
                {
                    save2=save+ctr;
                    ctr=ctr*2;
                }
                if(save2==save)
                    break;
                save=save2;
                ctr=1;
            }
            if(save+ctr>=v.size())
            {
                v.push_back(val);
            }
            else
            {
                v[save+ctr]=val;
            }
        }
        cout<<v.size()<<" ";
        for(j=0;j<v.size();j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
