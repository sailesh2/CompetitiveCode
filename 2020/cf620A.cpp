#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,x,y,a,b;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>x>>y>>a>>b;
        if((y-x)%(a+b)==0){
            cout<<(y-x)/(a+b)<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
