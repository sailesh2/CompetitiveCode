#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(a>b){
        if(a==9 && b==1){
            cout<<9<<" "<<10;
        }else{
            cout<<"-1";
        }
    }
    else if(a==b)
        cout<<a*10<<" "<<b*10+1;
    else{
        if(b-a==1){
            cout<<a<<" "<<b;
        }else{
            cout<<"-1";
        }
    }
    return 0;
}
