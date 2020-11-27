#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,a,b,c,maxi,mini;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>a>>b>>c;
        maxi=max(a,max(b,c));
        mini=min(a,min(b,c));
        if(abs(maxi-mini)<=2){
            cout<<"0\n";
        }else{
            cout<<(maxi-mini-2)*2<<"\n";
        }
    }
    return 0;
}
