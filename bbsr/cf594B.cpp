#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    long long int x=0,y=0;
    for(int i=0;i<n;i++){
        if(i<n/2)
        y=y+s[i];
        else
        x=x+s[i];
    }
    long long int d=x*x+y*y;
    cout<<d;
    return 0;
}
