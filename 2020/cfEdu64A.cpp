#include<bits/stdc++.h>
#define INF 1000
using namespace std;

int getPoints(int a, int b){
    if(a==b){
        return INF;
    }
    if(a==1 && b==2){
        return 3;
    }
    if(a==1 && b==3){
        return 4;
    }
    if(a==2 && b==1){
        return 3;
    }
    if(a==2 && b==3){
        return INF;
    }
    if(a==3 && b==1){
        return 4;
    }
    if(a==3 && b==2){
        return INF;
    }
}

int main(){
    int n,t;
    int sm=0,ctr=0;
    cin>>n;
    int arr[n];
    int save;
    for(int i=0;i<n;i++){
        cin>>t;
        arr[i]=t;
        if(i>0){

            int v=getPoints(arr[i-1],t);
            if(i>1){
                if(arr[i-2]==3 && arr[i-1]==1 && t==2)
                    v--;
            }
            if(v==INF){
                ctr=1;
            }
            sm=sm+v;
        }
    }

    if(ctr==0){
        cout<<"Finite\n";
        cout<<sm;
    }else{
        cout<<"Infinite";
    }
    return 0;
}
