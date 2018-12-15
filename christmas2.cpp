#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
    int i,n;
    long long int cntr=0,ctr,save,save1;
    cin>>n;
    multiset<int> st;
    multiset<int>::iterator it,it2;
    int arr[n],brr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    for(i=n-2;i>=0;i--)
    {
        st.insert(brr[i+1]);
        if(st.
        {
            save1=0;
            ctr=1;

            while(1)
            {
                if(st[save1+1]>=arr[i])
                    break;
                while(1)
                {
                    if(st[save1+ctr]>=arr[i])
                    {
                        ctr=1;
                        save1=save;
                        break;
                    }
                    save=save1+ctr;
                    ctr=ctr*2;
                }
            }
            cntr=cntr+save1+1;
        }
    }
    cout<<cntr<<"\n";
    return 0;
}
