#include<bits/stdc++.h>

using namespace std;

vector<long long int> tree[200005];
vector<long long int> treeHeads;
set<long long int> treeHeadSt;
long long int sm=0;

void buildTree(long long int* a, long long int* b, long long int n){

    for(long long int i=0;i<n;i++){
        if(b[i]!=-1)
            tree[b[i]-1].push_back(i);
    }
}

void clearTree(long long int n){
    sm=0;
    treeHeads.clear();
    treeHeadSt.clear();
    for(long long int i=0;i<=n;i++)
        tree[i].clear();
}

long long int createHeads(long long int root, long long int* a){

    long long int s = a[root];
    for(long long int i=0;i<tree[root].size();i++){
        long long int child = tree[root][i];
        long long int v = createHeads(child,a);
        if(v>=0)
            s=s+v;
        else{
            treeHeads.push_back(child);
            treeHeadSt.insert(child);
        }
    }
    sm=sm+s;
    return s;
}

void displayTree(long long int root){
    for(long long int i=0;i<tree[root].size();i++){
        long long int child = tree[root][i];
        if(treeHeadSt.count(child)==0)
            displayTree(child);
    }
    cout<<root+1<<" ";
}

int main(){
    long long int n;
        cin>>n;
        clearTree(n);
        long long int arr[n],brr[n];
        for(long long int j=0;j<n;j++){
            cin>>arr[j];
        }
        for(long long int j=0;j<n;j++){
            cin>>brr[j];
        }

        buildTree(arr,brr,n);

        for(long long int j=0;j<n;j++){
            if(brr[j]==-1){
                createHeads(j,arr);
                treeHeads.push_back(j);
            }
        }
        cout<<sm<<"\n";

        for(long long int j=treeHeads.size()-1;j>=0;j--){
            displayTree(treeHeads[j]);
        }

    return 0;
}
