#include<bits/stdc++.h>

using namespace std;

int binSear(int * stk,int top,int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<=top && stk[save+ctr]>cost){
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
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxA[n];
    int ctr[n];
    for(int i=0;i<n;i++){
        if(i==0){
            maxA[i]=arr[i];
            ctr[i]=1;
        }else{
            maxA[i]=max(arr[i],maxA[i-1]);
            ctr[i]=ctr[i-1];
            if(arr[i]>maxA[i-1])
                ctr[i]++;
        }
    }
    int bef,after,maxi=-1,save=-1;
    int stk[n];
    int top=-1,popped;
    for(int i=n-1;i>=0;i--){
        if(i==0){
            bef=0;
        }else{
            bef=ctr[i-1];
        }
        after=0;

        while(top!=-1 && arr[i]>=stk[top]){
            popped=(stk[top--]);
            if(i-1==-1 || popped>maxA[i-1]){
                after++;
            }
        }
        if(top!=-1){
            if(i-1==-1){
                after=after+top+1;
            }else{
                after=after+binSear(stk,top,maxA[i-1]);
            }
        }
        stk[++top]=arr[i];

        if(bef+after>maxi){
            maxi=bef+after;
            save=arr[i];
        }else if(bef+after==maxi){
            if(arr[i]<save){
                save=arr[i];
            }
        }


    }
    cout<<save;
    return 0;
}
