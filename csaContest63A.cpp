#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    int brr[m];
    int vtr=0,cnt=0;
    for(int i=0;i<m;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]+brr[i+j]!=1){
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            vtr++;
    }
    cout<<vtr;
    return 0;
}
