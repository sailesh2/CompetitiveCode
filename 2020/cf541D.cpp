#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int cnt=0;

        for(int j=0;j<n;j++){
            if(arr[j]==k){

                if(j+1<n && arr[j+1]>=k){
                        cnt=1;
                        break;

                }

                if(j-1>=0 && arr[j-1]>=k){
                        cnt=1;
                        break;

                }
            }
        }

        if(n==1 && arr[0]==k){
            cnt=1;
        }
        if(cnt==1){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
    return 0;
}
