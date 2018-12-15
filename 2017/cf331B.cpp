#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    long long int ctr=0,sm=0;
    for(int i=0;i<n;i++){
        if(b[i]!=sm){
            ctr=ctr+(abs(b[i]-sm));
            sm=b[i];
        }
    }
    cout<<ctr;
    return 0;
}
