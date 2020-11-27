#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int cnt2=0;
    int mini=1000;
    for(int i=0;i<=100;i++){
        int save=0;
        int cnt=0;
        for(int j=0;j<n;j++){
            int d =abs(arr[j]-i);
            if(d!=0){
                if(save==0)
                    save=d;
                else if(save!=d){
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==0){
            mini=min(mini,save);
            cnt2=1;
        }
    }
    if(cnt2==0){
        cout<<"-1";
    }else{
        cout<<mini;
    }
    return 0;
}
