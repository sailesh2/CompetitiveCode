#include<bits/stdc++.h>

using namespace std;

int main(){
    int h,w;
    cin>>w>>h;
    int w1,h1,w2,h2;
    cin>>w1>>h1;
    cin>>w2>>h2;
    for(int i=h;i>=0;i--){
        w=w+i;
        if(i==h1){
            w=max(0,w-w1);
        }
        if(i==h2){
            w=max(0,w-w2);
        }
    }
    cout<<w;
    return 0;
}
