#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int> > val;
int n;
void traverse(int root, int parentCost, vector<pair<int,int> >* tree){
//cout<<root<<"----\n";
    for(int i=0;i<tree[root].size();i++){
        pair<int,int> next = tree[root][i];
        int child=next.first;
        int cost=next.second;

        traverse(child,cost,tree);
    }

    if(val[parentCost+1].first==0){
        val[parentCost+1]=make_pair(val[parentCost].first+1,root);
    }else{
        for(int i=n;i>=parentCost+2;i--){
            val[i]=make_pair(val[i-1].first+1,val[i-1].second);
        }
        val[parentCost+1]=make_pair(val[parentCost].first+1,root);
    }
    //cout<<parentCost<<" "<<val[parentCost].first<<" "<<val[parentCost].second<<"\n";
}

int isFine(int root, int cost,vector<pair<int,int> >* tree, int* values){
    int c=values[root]<cost?1:0;
    for(int i=0;i<tree[root].size();i++){
        pair<int,int> next = tree[root][i];
        int child=next.first;

        c=c+isFine(child,cost,tree,values);
    }
    return c;
}

int main(){
    cin>>n;
    int p,c;
    int cm[n+1];
    vector<pair<int,int> > tree[n+1];
    for(int i=1;i<=n;i++){
        cin>>p>>c;
        tree[p].push_back(make_pair(i,c));
        cm[i]=c;
    }

    for(int i=0;i<=n;i++)
        val.push_back(make_pair(0,0));

    traverse(tree[0][0].first,tree[0][0].second,tree);
    int values[n+1];
    for(int i=1;i<=n;i++){
        values[val[i].second]=val[i].first;
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        //cout<<values[i]<<"\n";
        if(cm[i]!=isFine(i,values[i],tree,values)){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<values[i]<<" ";
    }else{
        cout<<"NO";
    }
    return 0;
}
