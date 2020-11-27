#include<bits/stdc++.h>

using namespace std;

long long int res(string s){
    long long int ctr=0;
    long long int sm=0;

    for(long long int i=0;i<s.length();i++){
        if(s[i]=='+'){
            ctr++;
        }else{
            ctr--;
        }

        if(ctr<0){
            sm=sm+i+1;
            ctr=0;
        }
    }

    long long int l=s.length();
    sm=sm+l;
    return sm;
}

int main(){
    int t;
    cin>>t;
    string s;

    for(int i=0;i<t;i++){
        cin>>s;
        cout<<res(s)<<"\n";
    }
    return 0;
}
