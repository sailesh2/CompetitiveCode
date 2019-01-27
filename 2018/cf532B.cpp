#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[m];
    int pool[n+1];
    int probSetCnt=0;
    for(int i=0;i<m;i++){
        cin>>arr[i];

    }

    for(int i=1;i<=n;i++){
        pool[i]=0;
    }


    for(int i=0;i<m;i++){
        if(pool[arr[i]]==0)
            probSetCnt++;
        pool[arr[i]]++;
        if(probSetCnt == n){
            cout<<"1";
            for(int j=1;j<=n;j++){
                pool[j]--;
                if(pool[j]==0)
                    probSetCnt--;
            }
        }else{
            cout<<"0";
        }
    }
    return 0;
}
