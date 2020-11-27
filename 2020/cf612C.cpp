#include<bits/stdc++.h>

using namespace std;
int n;
int dp[101][101][101][2];

void clearDP(int ev,int od){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=ev;j++){
            for(int k=0;k<=od;k++){
                dp[i][j][k][0]=-1;
                dp[i][j][k][1]=-1;
            }
        }
    }
}

int minParity(int index, int* arr, int ev, int od, int prev){
    if(index>=n)
        return 0;
    int v=0,v1,v2;
    //cout<<index<<"-----\n";
    if(arr[index]==0){
        if(ev>0){
            if(dp[index+1][ev-1][od][0]==-1)
                v1=minParity(index+1,arr,ev-1,od,0);
            else
                v1=dp[index+1][ev-1][od][0];
            if(index-1>=0){
                v1=v1+(prev==0?0:1);
            }
        }
        if(od>0){
            if(dp[index+1][ev][od-1][1]==-1)
                v2=minParity(index+1,arr,ev,od-1,1);
            else
                v2=dp[index+1][ev][od-1][1];
            if(index-1>=0){
                v2=v2+(prev!=0?0:1);
            }
        }
        if(ev>0 && od>0)
        v=min(v1,v2);
        else if(ev>0)
        v=v1;
        else if(od>0)
        v=v2;
    }else{
        if(index-1>=0){
            v=(prev==(arr[index]%2))?0:1;
        }
        if(dp[index+1][ev][od][arr[index]%2]==-1)
            v=v+minParity(index+1,arr,ev,od,arr[index]%2);
        else
            v=v+dp[index+1][ev][od][arr[index]%2];
    }
    //cout<<v<<"\n";
    dp[index][ev][od][prev]=v;
    return v;
}

int main(){
    cin>>n;
    int arr[n];
    int has[104]={0};
    int ev=0,od=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        has[arr[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(has[i]==0){
            if(i%2==0)
                ev++;
            else
                od++;
        }
    }

    clearDP(ev,od);
    cout<<minParity(0,arr,ev,od,0);
    return 0;
}
