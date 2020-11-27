#include<bits/stdc++.h>

using namespace std;

bool isZero(int a, int b){
    if((2*a-b)<0)
        return false;
    if((2*a-b)%3!=0)
        return false;
    int k=(2*a-b)/3;
    a=a-2*k;
    b=b-k;
    return a>=0 && b>=0;
}

int main(){
    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;

        if(isZero(a,b) || isZero(b,a)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
