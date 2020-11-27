#include<bits/stdc++.h>

using namespace std;

bool canSwap(int a, int b, int c, int d){
    return (a==c && b==d) || (a==d && b==c);
}

int main(){
    int t,n;
    cin>>t;
    for(int l=0;l<t;l++){
        cin>>n;
        int arr[n],brr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }

        if(n%2!=0 && arr[n/2]!=brr[n/2]){
            cout<<"No\n";
        }else{
            int cnt2=0;
            for(int i=n/2-1,j=n/2+n%2;i>=0;i--,j++){
                int req1=arr[i];
                int req2=arr[j];
                int cnt=0;
                for(int k1=i,k2=j;k1>=0;k1--,k2++){
                    int pre1=brr[k1];
                    int pre2=brr[k2];

                    if(canSwap(req1,req2,pre1,pre2)){

                        int temp=brr[k1];
                        brr[k1]=brr[i];
                        brr[i]=temp;

                        temp=brr[k2];
                        brr[k2]=brr[j];
                        brr[j]=temp;

                        cnt=1;
                        break;
                    }
                }

                if(cnt==0){
                    cnt2=1;
                    break;
                }
            }

            if(cnt2==0){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }
    return 0;
}
