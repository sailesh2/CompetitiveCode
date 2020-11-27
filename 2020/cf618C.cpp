#include<bits/stdc++.h>

using namespace std;
int ctr=0;
int digCtr[100005]={0};
void storeDig(int v){
    vector<int> digs;
    while(v>0){
        digs.push_back(v%2);
        v=v/2;
    }
    int dl=digs.size()-1;
    ctr=max(ctr,dl);
    for(int i=dl;i>=0;i--){
        if(digs[i]==1){
            digCtr[i]++;
        }
    }
}

bool isDig(int v, int d){
    vector<int> digs;
    while(v>0){
        digs.push_back(v%2);
        v=v/2;
    }
    int dl=digs.size()-1;
    if(d>dl)
        return false;
    return digs[d]==1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        storeDig(arr[i]);
    }
    int saveD=0;
    for(int i=ctr;i>=0;i--){
        if(digCtr[i]==1){
            saveD=i;
            break;
        }
    }
    //cout<<ctr<<"v"<<saveD<<"\n";
    sort(arr,arr+n);
    int save=0;
    for(int i=n-1;i>=0;i--){
        if(isDig(arr[i],saveD)){
            save=i;
            break;
        }
    }
    cout<<arr[save]<<" ";
    for(int i=n-1;i>=0;i--){
        if(i!=save)
            cout<<arr[i]<<" ";
    }
    return 0;
}
