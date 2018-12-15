#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t,p;
    cin>>n;
    float maxi=0;
    int save=0;
    for(int i=0;i<n;i++){
        cin>>t>>p;
        if(((float)(t-p)/p)>maxi){
            maxi=(float)(t-p)/p;
            save=i+1;
        }
    }
    cout<<save;
    return 0;
}
