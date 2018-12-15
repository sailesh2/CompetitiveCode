#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long int a,b;
    cin>>n;
    long long int ctr=0,sm=0,mini,save;
    vector<pair<long long int,long long int> > segments;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        segments.push_back(make_pair(a,b));
    }
    sort(segments.begin(),segments.end());
    for(int k=0;k<n;k++){
        ctr=0;
        save=0;
        for(int i=k-1;i>=0;i--){
            ctr=ctr+save+(long long int)(segments[i+1].first-segments[i].second);
            save=save+(long long int)(segments[i+1].first-segments[i].second);
        }
        sm=ctr;
        ctr=0;
        save=0;
        for(int i=k+1;i<n;i++){
            ctr=ctr+save+(long long int)(segments[i].first-segments[i-1].second);
            save=save+(long long int)(segments[i].first-segments[i-1].second);
        }
        sm=sm+ctr;
        if(k==0)
            mini=sm;
        else
            mini=min(mini,sm);
    }
    cout<<mini;
    return 0;
}
