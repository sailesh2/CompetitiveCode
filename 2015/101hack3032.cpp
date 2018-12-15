#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
    int i,n,k,j;
    long long int val1,val2;
    cin>>n>>k;
    multiset<pair<long long int,int> > st;
    multiset<pair<long long int,int> >::iterator it;

    int arr[n],brr[n],save,saved;
    long long int maxi=0;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
        cin>>brr[i];
    for(i=0;i<n;i++)
    {
        st.insert(make_pair(arr[i]*brr[i],i));
    }
    for(i=0;i<k;i++)
    {
        it=st.end();
        it--;
        val1=it->first;
        val2=it->second;
        arr[val2]--;
        st.erase(*it);
         st.insert(make_pair(arr[val2]*brr[val2],val2));
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
