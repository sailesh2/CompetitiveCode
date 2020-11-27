#include<bits/stdc++.h>

using namespace std;

bool ende(int* arr, int n){
    int save=-1;
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            save=i;
            break;
        }
    }

    for(int i=save;i<n;i++){
        if(arr[i]==i+1){
            for(int j=i;j<n;j++){
                if(arr[j]!=j+1)
                    return false;
            }
            return true;
        }
    }




    return true;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int x;
        int arr[n];
        int ctr=0;
        int cnt1=0,cnt2=0;
        for(int j=0;j<n;j++){
            cin>>x;
            arr[j]=x;
            if(x!=j+1){
                cnt1=1;
            }else{
                cnt2=1;
            }
        }
        if(cnt1==0)
            ctr=0;
        else if(cnt1==1 && cnt2==0)
            ctr=1;
        else if(ende(arr,n))
            ctr=1;
        else
            ctr=2;
        cout<<ctr<<"\n";
    }
    return 0;
}
