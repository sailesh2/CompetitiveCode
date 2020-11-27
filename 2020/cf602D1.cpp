#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}

bool comp2(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int main(){
    int n,x;
    cin>>n;
    pair<int,int> q[n];
    for(int j=0;j<n;j++){
        cin>>x;
        q[j]=make_pair(x,j);
    }
    sort(q,q+n,comp);

    vector<pair<int,int> > v[n];
    for(int i=0;i<n;i++){
        vector<pair<int,int> > temp;
        for(int j=0;j<=i;j++){
            temp.push_back(q[j]);
        }

        sort(temp.begin(),temp.end(),comp2);
        v[i]=(temp);
    }

    int m,k,pos;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>k>>pos;
        k--;
        pos--;
        cout<<v[k][pos].first<<"\n";
    }

    return 0;
}
