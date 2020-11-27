#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,c;
    cin>>n;
    int arr[n];
    int sm=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sm=sm+arr[i];
    }
    sort(arr,arr+n);
    int mini=sm,fac1,fac2;
    for(int j=n-1;j>=1;j--){
        int high=arr[j];
        int low=arr[0];
        for(int i=2;i*i<=high;i++){
            if(high%i==0){
                fac1=i;
                fac2=high/i;

                    if(sm- (high+low) + low*fac1+fac2<mini){
                        mini=sm- (high+low) + low*fac1+fac2;
                    }
                    if(sm - (high+low) + fac1+low*fac2<mini){
                        mini=sm - (high+low) + fac1+low*fac2;
                    }
            }
        }
    }
    cout<<mini;
    return 0;
}
