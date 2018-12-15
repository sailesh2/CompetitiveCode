#include<bits/stdc++.h>

using namespace std;
struct item{
    int t;
    int d;
    int p;
};
int n;
pair<int,vector<int> > dp[105][25];

void clearDP(){
    vector<int> v;
    for(int i=0;i<105;i++){
        for(int j=0;j<25;j++){
            dp[i][j]=make_pair(-1,v);
        }
    }

}

bool isEmptyPair(pair<int,vector<int> > p){
    return p.first!=-1;
}

pair<int,vector<int> > maxPrice(struct item *arr,int ind,int time){

    pair<int,vector<int> > p;
    int maxP=0,valP;
    vector<int> maxC,valC;

    if(time+arr[ind].t<=arr[ind].d){
        if(!isEmptyPair(dp[ind+1][time+arr[ind].t])){
            valP =(dp[ind+1][time+arr[ind].t]).first+arr[ind].p;
            valC =(dp[ind+1][time+arr[ind].t]).second;
            valC.push_back(ind);

        } else{
            p=maxPrice(arr,ind+1,time+arr[ind].t);
            valP=p.first+arr[ind].p;
            valC=p.second;
            valC.push_back(ind);
        }

        if(valP>maxP){
            maxP=valP;
            maxC=valC;
        }
    } else{
        if(!isEmptyPair(dp[ind+1][time])){
            valP =(dp[ind+1][time]).first;
            valC =(dp[ind+1][time]).second;

        } else{
            p=maxPrice(arr,ind+1,time);
            valP=p.first;
            valC=p.second;
        }

        if(valP>maxP){
            maxP=valP;
            maxC=valC;
        }
    }

    dp[ind][time]=make_pair(maxP,maxC);
    return dp[ind][time];
}
int main(){
    int t1,d1,p1;
    cin>>n;
    struct item arr[n];
    for(int i=0;i<n;i++){
        cin>>t1>>d1>>p1;
        arr[i].t=t1;
        arr[i].d=d1;
        arr[i].p=p1;
    }

    clearDP();
    pair<int,vector<int> > ans = maxPrice(arr,0,0);
    cout<<ans.first<<"\n";
    cout<<(ans.second).size()<<"\n";
    for(int i=0;i<(ans.second).size();i++){
        cout<<(ans.second)[i]<<" ";
    }
    return 0;
}
