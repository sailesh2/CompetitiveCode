#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        long long int d,h,x;
        cin>>n>>x;
        long long int ans,mini,maxi=0,maxDiff=0,saved;
        int cnt=0;
        long long int arr[n][2];
        for(int j=0;j<n;j++){
            cin>>d>>h;
            arr[j][0]=d;
            arr[j][1]=h;
            maxi=max(maxi,d);
        }
        for(int j=0;j<n;j++){
            d=arr[j][0];
            h=arr[j][1];
            if(d>=x){
                ans=1;
                cnt=2;
                break;
            }else{
                if(d>h){
                    long long int diff=d-h;
                    maxDiff=max(maxDiff,diff);
                    cnt=1;
                }
            }
        }

        if(cnt==0){
            cout<<"-1\n";
        }else if(cnt==1){
            ans=(long long int)ceil((double)(x-maxi)/maxDiff);
            if(ans>0 && (ans-maxi)<=0)
                ans++;
            cout<<ans<<"\n";
        }else{
            cout<<ans<<"\n";
        }
    }
    return 0;
}
