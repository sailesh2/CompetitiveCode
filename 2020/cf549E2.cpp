#include<bits/stdc++.h>

using namespace std;
int n,m,q;
void storeNext(int* per, int* next){
    for(int i=0;i<n;i++){
        next[per[i]]=per[(i+1)%n];
    }
}
int main(){
    cin>>n>>m>>q;

    int next[n+1];
    int p[n];

    int dpMinIndexP[m];
    int dpMaxCount[n+1];
    int dpFirstPos[n+1];
    int dpLastPos[n+1];
    int dpPrev[m];

    for(int i=0;i<n;i++){
        cin>>p[i];
        dpMaxCount[i]=-1;
        dpLastPos[i]=-1;
        dpFirstPos[i]=-1;
    }
    dpMaxCount[n]=-1;
    dpLastPos[n]=-1;
    dpFirstPos[n]=-1;
    storeNext(p,next);

    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
        dpPrev[i]=-1;
    }

    int mini=m+1;
    for(int i=m-1;i>=0;i--){
        int current = i;
        int currentVal = arr[i];
        int nextVal= next[currentVal];
        if(dpMaxCount[currentVal]<=min(dpMaxCount[nextVal]+1,n-1)){
            dpMaxCount[currentVal]=min(dpMaxCount[nextVal]+1,n-1);
            dpFirstPos[currentVal]=current;
            if(dpMaxCount[nextVal]+1>=n){

                if(dpLastPos[nextVal]!=-1){
                    dpLastPos[currentVal]=dpPrev[dpLastPos[nextVal]];
                }

            }else{
                dpLastPos[currentVal]=dpLastPos[nextVal];
            }
            if(dpLastPos[currentVal]==-1){
                    dpLastPos[currentVal]=current;
            }
        }
        if(dpFirstPos[nextVal]!=-1){
            dpPrev[dpFirstPos[nextVal]]=current;
        }
        if(dpMaxCount[currentVal]==n-1){
            mini=min(mini,dpLastPos[currentVal]);
            //cout<<mini<<"\n";
            dpMinIndexP[i]=mini;
        }else{
            dpMinIndexP[i]=m+1;
        }
    }

    int l,r;
    string cyclicShiftPerExists="";

    for(int i=0;i<q;i++){
        cin>>l>>r;
        l--;
        r--;
        if(dpMinIndexP[l]<=r){
            cyclicShiftPerExists.push_back('1');
        }else{
            cyclicShiftPerExists.push_back('0');
        }
    }
    cout<<cyclicShiftPerExists;
    return 0;
}
