#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,a,b,c;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>a>>b>>c;

        if(a<c){
            cout<<"1 ";
        }else{
            cout<<"-1 ";
        }

        if(a*b>c){
            cout<<b<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}
