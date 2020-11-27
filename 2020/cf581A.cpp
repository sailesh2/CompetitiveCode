#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int ctr=0;
    for(int i=s.length()-1;i>0;i=i-2){

        ctr++;
    }
    int l=s.length();
    int last;
    if(l%2!=0){
    for(int i=s.length()-1;i>0;i--){
        if(s[i]=='1'){

            ctr++;
            break;
        }
    }
    }

    cout<<ctr;
    return 0;
}
