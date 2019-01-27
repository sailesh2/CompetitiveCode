#include<bits/stdc++.h>

using namespace std;

int main(){
    string hand;
    cin>>hand;
    string table;
    int cnt=0;
    for(int i=0;i<5;i++){
        cin>>table;
        if(table[0]==hand[0] || table[1]==hand[1]){
            cnt=1;
        }
    }
    if(cnt==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
