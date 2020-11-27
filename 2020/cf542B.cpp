#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a;
    vector<pair<int,int> > first,second;
    set<int> has;

    for(int i=0;i<2*n;i++){
        cin>>a;
        if(has.count(a)==0){
            has.insert(a);
            first.push_back(make_pair(a,i));
        }else{
            second.push_back(make_pair(a,i));
        }
    }

    sort(first.begin(),first.end());
    sort(second.begin(),second.end());

    long long int path=0;

    for(int i=0;i<n;i++){
        if(i==0)
            path = path + (long long int)(abs(first[i].second));
        else
            path = path + (long long int)(abs(first[i].second - first[i-1].second));
    }
    for(int i=0;i<n;i++){
        if(i==0)
            path = path + (long long int)(abs(second[i].second));
        else
            path = path + (long long int)(abs(second[i].second - second[i-1].second));
    }

    cout<<path;
    return 0;
}
