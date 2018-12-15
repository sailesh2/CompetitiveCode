#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    int legs[n];
    int energy[201]={0};
    int x;
    vector<pair<int,int> > v;
    for(i=0;i<n;i++)
    {
        cin>>legs[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        energy[x]++;
        v.push_back(make_pair(legs[i],x));
    }
    sort(v.begin(),v.end());
    i=n-1;
    long long int sum=0,sm2,sum_e,mini=1000000000;
    int dif,ctr,cnt,j;
    while(i>=0)
    {
        //cout<<i<<" "<<sum<<"\n";
        //cout<<i<<" "<<sum<<"\n";
        ctr=0;
        sm2=0;
        while(i>0 && v[i].first==v[i-1].first)
        {
            energy[v[i].second]--;
            ctr++;
            sm2=sm2+v[i].second;
            i--;
        }
        energy[v[i].second]--;
        sm2=sm2+v[i].second;
        i--;
        ctr++;
        dif=n-(2*ctr-1);
   //     cout<<n<<" "<<ctr<<" "<<dif<<"\n";
        j=0;
        sum_e=sum;
        cnt=0;
        while(cnt<dif && j<=200)
        {
     //       cout<<j<<" "<<energy[j]<<"\n";
            if(cnt+energy[j]>=dif)
            {
                sum_e=sum_e+(dif-cnt)*j;
                cnt=dif;
                break;
            }
            sum_e=sum_e+energy[j]*j;
            cnt=cnt+energy[j];
            j++;
        }
       // cout<<sum_e<<"\n";
        if(sum_e<mini)
            mini=sum_e;
        sum=sum+sm2;
        n=n-ctr;
    }
    cout<<mini;
    return 0;
}
