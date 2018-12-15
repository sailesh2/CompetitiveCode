#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ctr=0,maxC=0,last=0,first=0;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]+1){
            ctr++;
            if(ctr>maxC){
                first=0;
                last=0;
                if(i==n-1){
                    last=1;
                }
                if(i-ctr==0){
                    first=1;
                }
                maxC=ctr;
            } else if(ctr==maxC){
                if(!(first == 1 && arr[0] == 1)){
                   if(i==n-1){
                        last=1;
                    }
                    if(i-ctr==0){
                        first=1;
                    }
                }
            }

        }else{
            ctr=0;
        }
    }
    if(!((first==1 && arr[0]==1) || (last==1 && arr[n-1]==1000)))
        maxC--;
    maxC=maxC>0?maxC:0;
    cout<<maxC;
    return 0;
}
