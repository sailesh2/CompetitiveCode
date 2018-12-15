#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s[n];
    long long int sm=0,ctr=0;
    for(int i=0;i<n;i++){
        ctr=0;
        cin>>s[i];
        for(int j=0;j<n;j++){
            if(s[i][j]=='C'){
                ctr++;
            }
        }
        sm=sm+(ctr*(ctr-1))/2;
    }

    for(int i=0;i<n;i++){
        ctr=0;
        for(int j=0;j<n;j++){
            if(s[j][i]=='C'){
                ctr++;
            }
        }
        sm=sm+(ctr*(ctr-1))/2;
    }
    cout<<sm;
    return 0;
}
