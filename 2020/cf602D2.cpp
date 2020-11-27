#include<bits/stdc++.h>

using namespace std;
int n;
int BTree[200005]={0};

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}
bool comp2(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}

int getSumBIT(int index)
{
    int sum = 0;

    index++;
    while (index>0)
    {
        sum += (BTree[index]);

        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int index)
{
    index++;
    int val=1;
    while (index <= n)
    {
        BTree[index] += val;

        index += index & (-index);
    }
}

int findPosBIT(int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<n && getSumBIT(save+ctr)<cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+1;
}

int main(){
    int m,x,k,pos;
    cin>>n;
    int arr[n];
    pair<int,int> q[n];
    for(int j=0;j<n;j++){
        cin>>x;
        arr[j]=x;
        q[j]=make_pair(x,j);
    }
    sort(q,q+n,comp);
    cin>>m;
    pair<int,int> brr[m];
    pair<int,int> queries[m];
    for(int i=0;i<m;i++){
        cin>>k>>pos;
        queries[i]=make_pair(k,pos);
        brr[i]=make_pair(k,pos);
    }

    sort(brr,brr+m,comp2);
    int ctr=0;
    map<pair<int,int>,int> ans;
    map<pair<int,int>,int>::iterator ansIt;
    for(int i=0;i<n;i++){
        updateBIT(q[i].second);
        while(ctr<m && brr[ctr].first-1==i){
            pos=findPosBIT(brr[ctr].second);
            ans.insert(make_pair(make_pair(i+1,brr[ctr].second),arr[pos]));
            ctr++;
        }
    }

    for(int i=0;i<m;i++){
        ansIt=ans.find(queries[i]);
        cout<<ansIt->second<<"\n";
    }
    return 0;
}
