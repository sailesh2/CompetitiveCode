#include<bits/stdc++.h>

using namespace std;

int ctr=0;
long long int sum=0;
int k,p;

void zcy(int * arr,int ind,int len){
    int mid=len/2-1;
    if(ind>mid){
        return;
    }
    long long int sum2=0;
    if(ind==mid){
        for(int i=0;i<=9;i++){
            arr[ind]=i;
            arr[len-1-ind]=i;
            sum2=0;
            for(int j=0;j<len;j++){
                sum2=(sum2*10+arr[j])%p;
            }
            sum=(sum+sum2)%p;
            ctr++;
            if(ctr==k)
                return;
        }
        return;
    }
    for(int i=0;i<=9;i++){
        arr[ind]=i;
        arr[len-1-ind]=i;
        if(ctr==k)
            return;
        zcy(arr,ind+1,len);
    }
}

int main(){
    cin>>k>>p;
    long long int sum2=0;
    int digs=4;
    for(int i=11;i<=99;i=i+11){
        sum=(sum+i)%p;
        ctr++;
        if(ctr==k)
            break;
    }
    while(ctr<k){
        int arr[digs];
        for(int i=1;i<=9;i++){
            arr[0]=i;
            arr[digs-1]=i;
            if(ctr==k)
                break;
            zcy(arr,1,digs);
        }
        if(ctr==k)
            break;
        digs=digs+2;
    }
    cout<<sum;
    return 0;
}
