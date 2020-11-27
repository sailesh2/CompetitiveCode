#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,x,y,a,b;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>x>>y>>a>>b;

        if(2*a<=b){
            cout<<a*(x+y)<<"\n";
        }else{
            cout<<a*(abs(x-y)) + b*(min(x,y))<<"\n";
        }
    }
    return 0;
}
