#include<bits/stdc++.h>

using namespace std;
int n;
long long int binSearLow(long long int cost, long long int *arr){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<n && arr[save+ctr]<=cost){
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

long long int binSearHigh(long long int cost,long long int *arr){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<n && arr[save+ctr]<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save;
}
int main(){
    long long int x,k,y;
    long long int low,high;
    cin>>n>>x>>k;
    long long int ctr=0,v1,v2;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        y=arr[i];
        if(k==0){
            if(y%x!=0){
                low=(y/x)*x;
                v1=binSearLow(low,arr);
                v2=binSearHigh(y,arr);

                if(v1<=v2){
                    ctr=ctr+v2-v1+1;
                }
            }
        }else{

            low=(y/x)*x-(k)*x;
            high=(y/x)*x-(k-1)*x;

            v1=binSearLow(low,arr);
            v2=binSearHigh(high,arr);

            if(v1<=v2){
                ctr=ctr+v2-v1+1;
            }
        }
    }
    cout<<ctr;
}
