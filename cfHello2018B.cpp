#include<bits/stdc++.h>

using namespace std;
vector<int> tree[1005];

bool isSpruce(int root){
    if(tree[root].size()==0)
        return true;
    int ctr=0,next;
    bool res;
    for(int i=0;i<tree[root].size();i++){
        next=tree[root][i];
        if(tree[next].size()==0){
            ctr++;
        }else{
            res=isSpruce(next);
            if(res==false)
                return false;
        }
    }
    return ctr>=3;
}
int main(){
    int n,p;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>p;
        tree[p].push_back(i+1);
    }
    if(isSpruce(1)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
