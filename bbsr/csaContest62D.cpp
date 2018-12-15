#include<bits/stdc++.h>

using namespace std;

int binSear(int cost,int * stk, int top){
    int ctr=1;
    int save=-1;
    int save2=-1;
    if(top==-1)
        return 0;
    while(1){
        while(save+ctr<=top && cost<stk[save+ctr]){
            save2=save+ctr;
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
    int n;
    cin>>n;
    int arr[n];
    int parm[n];
    int maxA[n];
    int maxi=0,ctr=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>maxi){
            parm[i]=++ctr;
            maxi=arr[i];
        }else{
            parm[i]=ctr;
        }
        maxA[i]=maxi;
    }
    int maxp=0,top=-1;
    int stk[n];
    int val,pm,d;
    for(int i=n-1;i>=0;i--){
        if(i==0){
            val=0;
            pm=0;
        }else{
            val=maxA[i-1];
            pm=parm[i-1];
        }
        d=binSear(val,stk,top);
        while(top!=-1 && stk[top]<=arr[i]){
            top--;
        }
        stk[++top]=arr[i];
        maxp=max(maxp,d+pm);
    }
    cout<<maxp;
    return 0;
}


