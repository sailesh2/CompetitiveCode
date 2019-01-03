#include<bits/stdc++.h>

using namespace std;

vector<int> sortCord(int one, int two, int thr){
    vector<int> sorted;
    if(one<=two && one<=thr){
        sorted.push_back(0);
        if(two<=thr){
            sorted.push_back(1);
            sorted.push_back(2);
        }else{
            sorted.push_back(2);
            sorted.push_back(1);
        }
    }else if(two<=one && two<=thr){
        sorted.push_back(1);
        if(one<=thr){
            sorted.push_back(0);
            sorted.push_back(2);
        }else{
            sorted.push_back(2);
            sorted.push_back(0);
        }
    }else{
        sorted.push_back(2);
        if(one<=two){
            sorted.push_back(0);
            sorted.push_back(1);
        }else{
            sorted.push_back(1);
            sorted.push_back(0);
        }
    }
    return sorted;
}

int main(){
    int x[3],y[3];
    set<pair<int,int> > mz;
    set<pair<int,int> >::iterator mzIt;
    cin>>x[0]>>y[0];
    cin>>x[1]>>y[1];
    cin>>x[2]>>y[2];

    vector<int> horder = sortCord(x[0],x[1],x[2]);
    vector<int> vorder = sortCord(y[0],y[1],y[2]);
    int ctr=0;
    vector<pair<int,int> > ans;
    for(int i=x[horder[0]];i<=x[horder[1]];i++){
        int j=y[horder[0]];
        if(mz.count(make_pair(i,j))==0){
            ctr++;
            ans.push_back(make_pair(i,j));
            mz.insert(make_pair(i,j));
        }
    }

    for(int j=y[vorder[0]];j<=y[vorder[2]];j++){
        int i=x[horder[1]];
        if(mz.count(make_pair(i,j))==0){
            ctr++;
            ans.push_back(make_pair(i,j));
            mz.insert(make_pair(i,j));
        }
    }

    for(int i=x[horder[2]];i>=x[horder[1]];i--){
        int j=y[horder[2]];
        if(mz.count(make_pair(i,j))==0){
            ctr++;
            ans.push_back(make_pair(i,j));
            mz.insert(make_pair(i,j));
        }
    }

    cout<<ctr<<"\n";
    for(int i=0;i<ctr;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    return 0;
}
