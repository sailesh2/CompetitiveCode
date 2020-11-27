#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int c=0,e=0,sc,se;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1)
            e++;
        else
            c++;
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        sc=0;
        se=0;
        for(int j=i;j<n;j=j+k){
            if(arr[j]==1)
                se++;
            else
                sc++;
        }
        for(int j=i;j>=0;j=j-k){
            if(j!=i){
            if(arr[j]==1)
                se++;
            else
                sc++;
            }
        }
        //cout<<abs( (e-se) - (c-sc) )<<"\n";
        maxi=max(maxi,abs( (e-se) - (c-sc) ));
    }
    cout<<maxi;
    return 0;
}
