#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    long long int n,a,b;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n>>a>>b;
        if(a*2<=b){
            cout<<n*a<<"\n";
        }else{
            cout<<(n/2)*b+(n%2)*a<<"\n";
        }
    }
    return 0;
}
