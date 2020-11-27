#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long int ctr=0;
    for(int i=0;i<n;i++){
        if(((int)s[i]-48)%2==0){
            ctr=ctr+i+1;
        }
    }
    cout<<ctr;
    return 0;
}
