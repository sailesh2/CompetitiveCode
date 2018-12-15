#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long int p,q,r;
    cin>>n>>p>>q>>r;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long long int maxi=-1000000000000000009;
    long long int maxi2=maxi;
    int save=-1,save2=-1;
    long long int hasMax[n],hasMax2[n];
    int saveMax[n],saveMax2[n];
    for(int i=n-1;i>=0;i--){
        if(r*arr[i]>maxi){
            maxi=r*arr[i];
            save=i;
        }
        hasMax[i]=maxi;
        saveMax[i]=save;

        if(q*arr[i]+hasMax[i]>maxi2){
            maxi2=q*arr[i]+hasMax[i];
            save2=i;
        }
        hasMax2[i]=maxi2;
        saveMax2[i]=save2;
    }

    long long int maxAns=-1000000000000000009;
    for(int i=0;i<n;i++){
        if(p*arr[i]+hasMax2[i]>maxAns){
            maxAns=p*arr[i]+hasMax2[i];
        }
    }
    cout<<maxAns;
    return 0;
}
