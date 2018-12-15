#include<bits/stdc++.h>

using namespace std;

int sm=0;
int isPossible=1;
int arr[6];

void breakTeam(int ind,int sum,int ctr){
    if(ind==6 || ctr==3){
        if(sum==sm/2 && ctr==3){
            isPossible=0;
        }
        return;
    }
    breakTeam(ind+1,sum+arr[ind],ctr+1);
    if(isPossible == 0)
        return;
    breakTeam(ind+1,sum,ctr);
}

int main(){
    for(int i=0;i<6;i++){
        cin>>arr[i];
        sm=sm+arr[i];
    }
    if(sm%2==0){
        breakTeam(0,0,0);
    }else{
        isPossible=1;
    }
    if(isPossible==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
