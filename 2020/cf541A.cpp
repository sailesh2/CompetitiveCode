#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    long long int ans = w1+2*h1+2 + w2+2*h2+2 + w1-w2;
    cout<<ans;
    return 0;
}
