#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0,ctr=0,ctr2=0,l;
    for(int i=0;i<n;i++){
        if(arr[i]==31){
            if(ctr==0){
                ctr=1;
            }else{
                if(ctr==1){
                    ctr++;
                }else{
                    cnt=1;
                    break;
                }
            }
        }else if(arr[i]==30){
            if(ctr==1 || ctr==2){
                ctr=0;
            }else{
                cnt=1;
                break;
            }
        }else if(arr[i]==29){
            if(((i-1>=0 && arr[i-1]==30) || (i+1<n && arr[i+1]==30))){
                cnt=1;
                break;
            }
        }else{
            if(l==28 || ((i-1>=0 && arr[i-1]==30) || (i+1<n && arr[i+1]==30))){
                cnt=1;
                break;
            }
            l=28;
        }
    }

    if(cnt==1){
        cout<<"NO";
    }else{
        for(int i=0;i<n;i++){
            if(arr[i]==28 || arr[i]==29){
                ctr=1;
                ctr2=0;
                for(int j=i+1;j<n;j++){
                    if(ctr2==5){
                        if(arr[j]!=31){
                            cnt=1;
                            break;
                        }
                    }else if(ctr2==11){
                        if(arr[j]!=29){
                            if(arr[j]==28 && arr[i]==29){

                            }else{
                                cnt=1;
                                break;
                            }
                        }
                        break;
                    }else{
                        if(arr[j]!=30+ctr){
                            cnt=1;
                            break;
                        }
                        ctr=1-ctr;
                    }
                    ctr2++;
                }
            }
            if(cnt==1)
                break;
        }
        if(cnt==1){
            cout<<"NO";
        }else{
            cout<<"YES";
        }
    }
    return 0;
}
