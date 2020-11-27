#include<bits/stdc++.h>

using namespace std;

string formStr(int n, int dl){
    string s="";
    for(int i=0;i<n-dl;i++)
        s.push_back('9');

    for(int i=0;i<dl;i++)
        s.push_back('8');

    return s;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int digL = n/4 + ((n%4==0)?0:1);
        cout<<formStr(n,digL)<<"\n";
    }
    return 0;
}
