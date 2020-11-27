#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,n;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n;
        int arr[n];
        int has[3000]={0};
        for(int j=0;j<n;j++){
            cin>>arr[j];
            if(arr[j]<=2048)
            has[arr[j]]++;
        }

        int num=2048;
        int ctr=1;
        int cnt=0;
        while(num>0){
            if(has[num]>=ctr){
                cnt=1;
                break;
            }
            ctr=(ctr-has[num])*2;
            num=num/2;
        }
        if(cnt==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
