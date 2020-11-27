#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    long long int availble[300]={0};
    string s;
    cin>>s;
    char c;
    for(long long int i=0;i<k;i++){
        cin>>c;
        availble[(int)c]=1;
    }

    long long int sm=0,ctr=0;

    for(long long int i=0;i<n;i++){
        if(availble[(int)s[i]]==1){
            ctr++;
        }else{
            sm=sm+(ctr*(ctr+1))/2;
            ctr=0;
        }
    }
    sm=sm+(ctr*(ctr+1))/2;
    cout<<sm;
    return 0;
}
