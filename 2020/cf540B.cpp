#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<long long int,long long int> > forw;
    vector<pair<long long int,long long int> > backw;

    long long int one=0,two=0;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            forw.push_back(make_pair(two,one));
            one=one+arr[i];
        }
        else{
            forw.push_back(make_pair(one,two));
            two=two+arr[i];
        }
        cnt=1-cnt;
    }

    one=0;
    two=0;
    cnt=0;

    for(int i=n-1;i>=0;i--){
        if(cnt==0){
            backw.push_back(make_pair(two,one));
            one=one+arr[i];
        }
        else{
            backw.push_back(make_pair(one,two));
            two=two+arr[i];
        }
        cnt=1-cnt;
    }

    int ctr=0;
    for(int i=0;i<n;i++){
        if(forw[i].first+backw[n-1-i].second == forw[i].second+backw[n-1-i].first)
            ctr++;
    }
    cout<<ctr;
    return 0;
}
