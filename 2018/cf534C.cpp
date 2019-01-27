#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int ver=0,hor=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            if(ver==0){
                cout<<"1 1\n";
            }else{
                cout<<"3 1\n";
            }
            ver=1-ver;
        }else{
            if(hor==0){
                cout<<"3 3\n";
            }else{
                cout<<"3 1\n";
            }
            hor=1-hor;
        }
    }
    return 0;
}
