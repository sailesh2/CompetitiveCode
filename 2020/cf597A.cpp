#include<bits/stdc++.h>

using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(gcd(a,b)==1){
            cout<<"Finite\n";
        }else{
            cout<<"Infinite\n";
        }
    }
    return 0;
}
