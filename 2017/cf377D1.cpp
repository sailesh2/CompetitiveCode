#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int arr[100005];
int crr[100005];
int brr[100005];
int n,m;

bool check(int ind){
    int has[100005]={0};
    int ctr=0,a;
    int ans[100005];
    if(crr[ind]<m)
        return false;
    for(int i=ind;i>=0;i--){
        if(arr[i]>0 && has[arr[i]]==0){
            ans[ctr++]=i;
            has[arr[i]]=1;
        }
    }
    int rem=0,save=-1,cnt=0;
    for(int i=ctr-1;i>=0;i--){
        a=arr[ans[i]];
        if(ans[i]-save-1+rem < brr[a-1]){
            cnt=1;
            break;
        }
        rem=rem+(ans[i]-save-1) - brr[a-1];
        save=ans[i];
    }
    //cout<<cnt;
    return cnt==0;
}

int binSear(){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<n && !check(save+ctr)){
            save2=save+ctr;
            //cout<<save2<<" ";
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+1;
}

int main(){
    cin>>n>>m;
    int has[100005]={0};

    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>0 && has[arr[i]]==0){

            if(i!=0)
                crr[i]=crr[i-1]+1;
            else
                crr[i]=1;

            has[arr[i]]=1;
        } else{
            if(i==0)
                crr[i]=0;
            else
                crr[i]=crr[i-1];
        }
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    int val=binSear()+1;
    if(val>n){
        cout<<"-1";
    } else{
        cout<<val;
    }
    return 0;
}
