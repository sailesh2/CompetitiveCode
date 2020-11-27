#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,s;
    cin>>n>>s;
    if((s-2*n)>=0){
        cout<<"YES\n";
        for(int i=0;i<n-1;i++){
            cout<<"2 ";
        }
        cout<<s-2*(n-1)<<"\n";
        cout<<"1";
    }else{
        cout<<"NO";
    }
    return 0;
}
