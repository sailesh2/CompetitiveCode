#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        int brr[n];
        bool possign[n],negsign[n];

        for(int j=0;j<n;j++){
            cin>>arr[j];
            if(j==0){
                possign[j]=arr[j]==1;
                negsign[j]=arr[j]==-1;
            }else{
                possign[j]=arr[j]==1 || possign[j-1];

                negsign[j]=arr[j]==-1 || negsign[j-1];
            }

        }
        for(int j=0;j<n;j++){
            cin>>brr[j];
        }
        int cnt=0;
        for(int j=n-1;j>=0;j--){
            if(arr[j]!=brr[j]){
                if(arr[j]>brr[j]){
                    if(j-1<0 || !negsign[j-1]){
                        cnt=1;
                        break;
                    }
                }else{
                    if(j-1<0 || !possign[j-1]){
                        cnt=1;
                        break;
                    }
                }
            }
        }

        if(cnt==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
