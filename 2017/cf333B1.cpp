#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int i=0;
    int j=0;
    int maxi=0;
    int ctr[100005]={0};
    while(i<=j && j<n){
        if(arr[j]-2>=0 && ctr[arr[j]-2]>0){
            while(i<=j){
                ctr[arr[i]]--;
                i++;
                if(ctr[arr[j]-2]==0)
                    break;
            }
            if(i>j){
                j++;
            }
        } else if(arr[j]+2<100005 && ctr[arr[j]+2]>0){
            while(i<=j){
                ctr[arr[i]]--;
                i++;
                if(ctr[arr[j]+2]==0)
                    break;
            }
            if(i>j){
                j++;
            }
        }
        else{
            maxi=max(maxi,j-i+1);
            ctr[arr[j]]++;
            j++;
        }
    }
    cout<<maxi;
    return 0;
}
