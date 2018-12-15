#include<bits/stdc++.h>

using namespace std;
int has[200005];
int pow2[20];
int ans[200005];

void createPow(){
    pow2[0]=1;
    for(int i=1;i<20;i++){
        pow2[i]=pow2[i-1]*2;
    }
}

void binSear(int n){
    ans[1]=0;
    ans[2]=1;
    int i=3;
    while(i<=pow2[n]){
        int ctr=1;
        int save=-1;
        int save2=-1;

        while(1){
            while(save+ctr<=n && has[save+ctr]<i){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        ans[i]=save;
        i++;
    }
}

void createHash(int * arr,int n){
    has[0]=0;
    has[1]=1;
    int ctr=2,maxi,maxi2,mini,cnt;
    while(ctr<=n){
        maxi=0;
        maxi2=0;
        cnt=0;
        mini=1000000000;
        for(int i=0;i<pow2[n];i++){
            cnt++;
            if(arr[i]>=maxi){
                maxi2=maxi;
                maxi=arr[i];
            }else{
                maxi2=max(maxi2,arr[i]);
            }
            if(cnt==pow2[ctr]){
                mini=min(mini,maxi2);
                maxi=0;
                maxi2=0;
                cnt=0;
            }
        }
        has[ctr]=mini;
        ctr++;
    }
}
int main(){
    int t,n;
    cin>>t;
    createPow();
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[pow2[n]];
        for(int j=0;j<pow2[n];j++){
            cin>>arr[j];
        }
        createHash(arr,n);
        binSear(n);
        for(int j=1;j<=pow2[n];j++){
            cout<<ans[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
