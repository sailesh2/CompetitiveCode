#include<bits/stdc++.h>

using namespace std;

bool isPresent(vector<int>* ngb, int inp, int out){
    for(int i=0;i<ngb[inp].size();i++){
        if(ngb[inp][i]==out)
            return true;
    }
    return false;
}

int main(){
    int n,a,b,c;
    cin>>n;
    int cnt[500005]={0};
    vector<int> ngb[n+1];
    for(int i=0;i<n-2;i++){
        cin>>a>>b>>c;
        if(!isPresent(ngb, a, b))
            ngb[a].push_back(b);
        if(!isPresent(ngb, a, c))
            ngb[a].push_back(c);

        if(!isPresent(ngb, b, a))
            ngb[b].push_back(a);
        if(!isPresent(ngb, b, c))
            ngb[b].push_back(c);

        if(!isPresent(ngb, c, a))
            ngb[c].push_back(a);
        if(!isPresent(ngb, c, b))
            ngb[c].push_back(b);

        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
    }
    int start=1;
    for(int i=1;i<=n;i++){
        if(cnt[i]==1){
            start=i;
            break;
        }
    }

    vector<int> ans;
    set<int> taken;
    taken.insert(start);
    ans.push_back(start);
    if(cnt[ngb[start][0]]<cnt[ngb[start][1]]){
        taken.insert(ngb[start][0]);
        ans.push_back(ngb[start][0]);

        taken.insert(ngb[start][1]);
        ans.push_back(ngb[start][1]);

    }else{
        taken.insert(ngb[start][1]);
        ans.push_back(ngb[start][1]);

        taken.insert(ngb[start][0]);
        ans.push_back(ngb[start][0]);
    }

    while(ans.size()<n){
        start=ans.size();
        start=start-2;
        start=ans[start];
        for(int i=0;i<ngb[start].size();i++){
            if(taken.count(ngb[start][i])==0){
                taken.insert(ngb[start][i]);
                ans.push_back(ngb[start][i]);
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
