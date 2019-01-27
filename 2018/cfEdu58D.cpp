#include<bits/stdc++.h>

using namespace std;
int maxLen=0;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

pair<int,int> maxLenGCD(int root, int parent, vector<int> * tree, int* arr){
    if(arr[root]==1)
        return make_pair(1,0);
    int maxi=arr[root];
    int len=1,maxi1=0,maxi2=0;
    pair<int,int> ret;
    int g,g1;
    for(int i=0;i<tree[root].size();i++){
        if(parent != tree[root][i]){
            ret=maxLenGCD(tree[root][i],root,tree,arr);
            g=ret.first;
            g1=gcd(g,arr[root]);
            if(g1>1){
                if(ret.second>=maxi1){
                    maxi2=maxi1;
                    maxi1=ret.second;
                }else{
                    maxi2=max(maxi2,ret.second);
                }
            }
            if(g1>maxi){
                maxi=g1;
                len = ret.second+1;
            }else if(g1==maxi){
                len = max(len,ret.second+1);
            }
        }
    }
    maxLen=max(maxLen,len);
    maxLen=max(maxLen,maxi1+maxi2+1);
    return make_pair(maxi,len);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> tree[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    maxLenGCD(0,-1,tree,arr);
    cout<<maxLen;
    return 0;
}
