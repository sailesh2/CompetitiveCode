#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    int stones=0;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='+')
            stones++;
        else{
            if(stones>0)
                stones--;
        }
    }
    cout<<stones;
    return 0;
}
