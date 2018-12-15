#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int main()
{
    int i,j,n,q,l,k,val,save,save2,ctr,idx,sum2,sum;
    cin>>n>>q;
    int arr[n],brr[n],ind[100001],tree[100001]={0};
    for(i=0;i<100000;i++)
        ind[i]=-1;
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
        arr[i]=brr[i];
        ind[arr[i]]=i;

    }
    for(i=0;i<n;i++)
    {
        idx=i+1;
        val=1;
        while (idx <=n)
        {
            tree[idx-1] = tree[idx-1] + val;
            idx += (idx & -idx);
        }
    }
    sort(brr,brr+n);
      map<pair<int,int>,int> has;
    vector<int> query[1001];
    set<int> st;
    for(i=0;i<q;i++)
    {

        cin>>l>>k;
        has.insert(make_pair(make_pair(l,k),i+1));
        query[l].push_back(k);
        st.insert(l);

    }




    int ans[q+1];
    for(i=1;i<=brr[n-1];i++)
    {
        val=i;
        if(st.count(val)!=0)
        {
            //cout<<val<<" ";
            for(j=0;j<query[val].size();j++)
            {
                k=query[val][j];
              //  cout<<k<<" ";




            //cout<<k<<"--";
            save=-1;
            save2=-1;
            ctr=1;
            while(1)
            {
                while(1)
                {
                    if(save+ctr>=n)
                        break;

                    idx=save+ctr+1;
                    sum = 0;
                    while (idx > 0)
                    {
                        sum = (sum + tree[idx-1]);
                        idx -= (idx & -idx);
                    }

                    if(sum>k)
                        break;

                    save2=save+ctr;
                    ctr=ctr*2;
                }
                if(save==save2)
                    break;
                save=save2;
                ctr=1;
            }
            //cout<<arr[save]<<" ";
            ans[has[make_pair(val,k)]]=arr[save];
            //cout<<brr[i]<<" "<<arr[save]<<"\n";
        }
        }
        //cout<<"\n";
        k=ind[val]+2;
        if(ind[val]>=0)
        {
        val=-1;
        while (k <=n)
        {
            tree[k-1] = tree[k-1] + val;
            k += (k & -k);
        }
        }
    }
    for(i=1;i<=q;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}
