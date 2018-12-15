#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>


using namespace std;

int has[100005]={0};
int arr[100005];
map<int,int> mp;
vector<vector<int> > ans;
vector<int> v;
void findLoop(int);
int main(){
    int n;
    cin>>n;
    int brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        brr[i]=arr[i];
    }
    sort(brr,brr+n);
    for(int i=0;i<n;i++){
        mp.insert(make_pair(brr[i],i));
    }
    for(int i=0;i<n;i++){
        if(has[i]==0){
            findLoop(i);
            ans.push_back(v);
            v.clear();
        }
    }

    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].size()<<" ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]+1<<" ";
        }
        cout<<"\n";
    }
}

void findLoop(int i){
    if(has[i]==1)
        return;
    has[i]=1;
    v.push_back(i);
    int next=mp.find(arr[i])->second;
    findLoop(next);
}
