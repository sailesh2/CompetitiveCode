#include<stdio.h>
#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> arr[100005];
int crr[100005];
int has[100005];
int canRoot[100005];
int cal(int index);
int fun(int index,int value);
int main(){
    int n;
    cin>>n;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>crr[i];
    }
    has[1]=1;
    cal(1);
    int val = fun(1,crr[1]);
    has[1]=0;

    if(val==-1) {
        cout<<"NO";
    }else{
        cout<<"YES\n"<<val;
    }
    return 0;
}

int cal(int index){
    int nv,val=0,c=crr[index],canBe=0;
    for(int i=0;i<arr[index].size();i++){
        nv=arr[index].at(i);
        if(has[nv]==0){
            has[nv]=1;
            val=cal(nv);
            if(val==0){
                if(c!=crr[nv]){
                    canBe=1;
                }
            }else {
                canBe=1;
            }
            has[nv]=0;
        }
    }
    canRoot[index]=canBe;
    return canBe;
}

int fun(int index,int value){
    int nv,ctr=0,nextV,c=0,val;
    for(int i=0;i<arr[index].size();i++){
        nv=arr[index].at(i);
        if(has[nv]==0){
            if(canRoot[nv]==1){
                ctr++;
               // cout<<"cantRoot"<<nv<<" "<<ctr<<"\n";
                if(ctr==2)
                    return -1;
                nextV=nv;
            } else {
             //   cout<<"canRoot\n";
                if(crr[index]!=crr[nv]){
                    c=1;
                }
            }
        }
    }
    if(ctr==0)
        return index;
    else{
        if(c==1)
            return -1;
        else {
            if(value!=crr[index])
                return -1;
            else {
                has[nextV]=1;
                //cout<<nextV<<"\n";
                val= fun(nextV,value);
                has[nextV]=0;
                return val;
            }
        }
    }
}
