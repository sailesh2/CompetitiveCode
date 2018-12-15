#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int i,n,k,p,cnt,save,save2;
    cin>>n>>k;
    int status[n];
    for(i=0;i<n;i++)
        cin>>status[i];
    cin>>p;
    int pr[p];
    int has[100005]={0};
    for(i=0;i<p;i++)
    {
        cin>>pr[i];
        has[pr[i]]=1;
    }
    sort(pr,pr+p);
    vector<int> pre;
    for(i=0;i<p;i++)
    {
        if(status[pr[i]-1]==1)
            pre.push_back(pr[i]);
    }


    int ctr=0,point=0;
    int counter[100005]={0};


    for(i=1;i<=n;i++)
    {
        //cout<<i<<" "<<ctr<<"\n";
        if(has[i]==1)
        {
            //cout<<"in has\n";
            if(status[i-1]!=3)
            {
                ctr++;
                counter[i]=ctr;
            }
        }
        else
        {
           // cout<<"else\n";
            if(status[i-1]!=3)
            {
                while(point<pre.size())
                {
                    if(counter[pre[point]]!=0 && ctr-counter[pre[point]]>=k)
                        break;
                    point++;
                }

                if(point>=pre.size())
                {
                    point=0;

                    while(point<pre.size())
                    {
                        if(counter[pre[point]]!=0 && ctr-counter[pre[point]]>=k)
                            break;
                        point++;
                    }
                    if(point>=pre.size())
                        point=0;
                }

                if(counter[pre[point]]!=0 && ctr-counter[pre[point]]>=k)
                {
                    ctr++;
                    counter[i]=ctr;
                    counter[pre[point]]=ctr;
                }
            }
        }
    }
    cout<<ctr;
    return 0;
}
