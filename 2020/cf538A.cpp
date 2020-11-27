#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y,z,g,p,b,rem;
    cin>>x>>y>>z;
    cin>>g>>p>>b;
    if(g<x){
        cout<<"NO";
    }else{
        g=g-x;
        rem=g+p;
        if(rem<y){
            cout<<"NO";
        }else{
            rem=rem-y;
            rem=rem+b;
            if(rem<z){
                cout<<"NO";
            }else{
                cout<<"YES";
            }
        }
    }
    return 0;
}
