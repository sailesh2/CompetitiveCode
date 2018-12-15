#include<bits/stdc++.h>

using namespace std;

int main(){
    int k,p;
    cin>>k>>p;
    int ctr=0;
    int sum=0,sum2=0;
    int digs=2,mid;
    while(ctr<=k){
        int arr[digs];
        for(int i=0;i<digs;i++){
            arr[digs]=0;
        }
        arr[0]=1;
        arr[digs-1]=1;
        mid=digs/2-1;

        while(1){
            arr[mid]++;
            arr[digs-1-mid]++;
            sum2=0;
            for(int i=0;i<digs;i++){
                sum2=(sum2*10+arr[digs])%p;
            }
            sum=(sum+sum2)%p;
            ctr++;
            if(ctr==k)
                break;
            if(arr[mid]==9){
                mid--;
                if(mid==-1)
                    break;
                for(int i=mid;i<=digs-1-mid;i++){
                    arr[i]=0;
                }
            }
        }
        if(ctr==k)
            break;
        digs=digs+2;
    }
    cout<<sum;
    return 0;
}
