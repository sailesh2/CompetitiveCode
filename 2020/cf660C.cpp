#include<bits/stdc++.h>

using namespace std;

int maxPeople[100005];
int ruinMoods[100005];

int fillMaxPeople(int root, vector<int>* tree, int* p, int* has){
    int s=p[root];
    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];

        if(has[child]==0){
            has[child]=1;
            s=s+fillMaxPeople(child,tree,p,has);
        }
    }
    maxPeople[root]=s;
    return s;
}

pair<bool,int> correctRuinMoods(int root, vector<int>* tree, int* has, int* p, int* h){
    int rm=0;
    int alm = max(0,ruinMoods[root]-p[root]);
    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];
        if(has[child]==0){
            has[child]=1;
            pair<bool,int> rmd = correctRuinMoods(child,tree,has,p,h);
            if(!rmd.first)
                return make_pair(false,-1);
            rm=rm+rmd.second;
        }
    }

    //cout<<"R---"<<root<<" "<<ruinMoods[root]<<" "<<rm<<"\n";

    if(ruinMoods[root]-rm>=0){
        if(ruinMoods[root]-rm<=p[root])
            return make_pair(true,ruinMoods[root]);
        else
            return make_pair(false,-1);
    }else{
            return make_pair(true,ruinMoods[root]);
    }
}

pair<bool,int> happy(int mp, int hp){
    if((mp+hp)%2!=0)
        return make_pair(false,-1);
    if((mp-hp)<0)
        return make_pair(false,-1);

    int x = (mp+hp)/2;
    int y=(mp-hp)/2;
    if(x>mp || y>mp || x<0 || y<0)
        return make_pair(false,-1);
    return make_pair(true,(mp-hp)/2);
}

bool correctHappiniesData(int root, vector<int>* tree, int* h, int* has){
    pair<bool,int> hData = happy(maxPeople[root], h[root]);

    if(!hData.first)
        return false;

    ruinMoods[root] = hData.second;

    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];

        if(has[child]==0){
            has[child]=1;
            if(!correctHappiniesData(child,tree,h,has))
                return false;
        }
    }

    return true;
}

int main(){
    int t,n,m,x,y;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        int p[n],h[n];
        vector<int> tree[n];
        for(int j=0;j<n;j++){
            cin>>p[j];
        }
        for(int j=0;j<n;j++){
            cin>>h[j];
        }
        for(int j=0;j<n-1;j++){
            cin>>x>>y;
            x--;
            y--;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        int has[100005]={0};
        has[0]=1;
        fillMaxPeople(0,tree,p,has);

        int has2[100005]={0};
        has2[0]=1;
        if(correctHappiniesData(0,tree,h,has2)){
            int has3[100005]={0};
            has3[0]=1;
            if(correctRuinMoods(0,tree,has3,p,h).first){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
        else
            cout<<"NO\n";
    }
    return 0;
}
