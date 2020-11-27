#include<bits/stdc++.h>

using namespace std;

int n,m;

pair<bool,int> isSymmetric(vector<int> segments){
    if(segments.size()<2)
        return make_pair(false,-1);
    sort(segments.begin(),segments.end());
    int cnt=0;
    int saveD;
    for(int i=1;i<segments.size();i++){
        int d=segments[i]-segments[i-1];

        if(cnt==0){
            cnt=1;
            saveD=d;
        }else{
            if(saveD!=d)
                return make_pair(false,d);
        }

    }
    int d =n-segments[segments.size()-1]+segments[0];
    if(cnt==0){
        return make_pair(true,d);
    }else if(cnt==1){
        return make_pair(saveD==d,d);
    }else{
        return make_pair(true,d);
    }
}

int main(){
    cin>>n>>m;
    int a,b;
    vector<int> diff[n+1];
    int maxD[100005]={0};
    for(int i=0;i<m;i++){
        cin>>a>>b;
        int d = max(a,b)-min(a,b);
        if(d>n/2)
            d=n-d;
        maxD[d]=max(maxD[d],max(a,b));
        diff[d].push_back(min(a,b));
    }

    int cnt=0;
    vector<int> rots;
    for(int i=0;i<n+1;i++){
        if(diff[i].size()>0){
            diff[i].push_back(maxD[i]);
            pair<bool,int> sym = isSymmetric(diff[i]);
            if(!sym.first)
            {
                cout<<sym.second;
                cnt=1;
                break;
            }else{
                rots.push_back(sym.second);
            }
        }
    }
    if(cnt==0){
        sort(rots.begin(),rots.end());
        for(int i=0;i<rots.size()-1;i++){
            if(rots[rots.size()-1]%rots[i]!=0){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }else{
        cout<<"No";
    }
    return 0;
}
