#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,n;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;
        n--;
        if(n%2==0){
            string s="7";
            for(long long int j=0;j<n/2-1;j++)
                s.push_back('1');
            cout<<s<<"\n";
        }else{
            string s="";
            for(long long int j=0;j<1+n/2;j++)
                s.push_back('1');
            cout<<s<<"\n";
        }
    }
    return 0;
}
