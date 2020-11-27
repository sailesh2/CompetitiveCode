#include<bits/stdc++.h>

using namespace std;
struct DaysComparator{
    bool operator()(pair<long long int,vector<long long int> > a , pair<long long int,vector<long long int> > b){
        if(a.first==b.first){
            long long int sma=0,smb=0;
            for(long long int i=0;i<a.first;i++){
                sma=sma+a.second[i];
                smb=smb+b.second[i];
            }
            return sma<smb;
        }
        return a.first<b.first;
    }
};
int main(){
    long long int n,m;
    cin>>n>>m;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    multiset<pair<long long int,vector<long long int> > , DaysComparator> days;
    multiset<pair<long long int,vector<long long int> > >::iterator daysIt;
    long long int cups;
    long long int ctr;
    long long int sm=0,sm2=0;
    for(long long int i=n-1;i>=0;i--){
        ctr=0;
        sm2=0;
        vector<long long int> v;
        while(i>=0 && sm2+arr[i]-ctr>sm2){
            sm2=(sm2+arr[i])-ctr;
            v.push_back(arr[i]-ctr);
            ctr++;
            i--;
         }
         //cout<<sm2<<" "<<ctr<<"\n";
         sm=sm+sm2;
        days.insert(make_pair(ctr,v));
        if(sm>=m)
            break;
        i++;
    }

    while(sm<m){
        daysIt=days.end();
        daysIt--;
        cups = daysIt->first;
        vector<long long int> v=daysIt->second;
        if(cups==1)
            break;
        sm=sm+cups-1;
        cups--;
        days.erase(daysIt);
        vector<long long int> v1;
        v1.push_back(v[cups]+cups);
        days.insert(make_pair(1,v1));
        vector<long long int> v2;
        for(long long int i=0;i<cups;i++){
            v2.push_back(v[i]);
        }
        days.insert(make_pair(cups,v2));
    }
    if(sm<m)
        cout<<"-1";
    else{
        sm2=0;
        daysIt=days.end();
        long long int ctr=0;
        while(sm2<m){
            daysIt--;
            cups = daysIt->first;
            vector<long long int> v=daysIt->second;

            for(long long int i=0;i<cups;i++){
                sm2=sm2+v[i];
            }
            ctr++;
        }
        cout<<ctr;
    }
    return 0;
}
