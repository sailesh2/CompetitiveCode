#include<bits/stdc++.h>

using namespace std;

bool isPrime(long long int n){
    for(long long int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

long long int main(){
    long long int n;
    cin>>n;
    if(!isPrime(8+n)){
        cout<<8+n<<" "<<8;
    }else{
        cout<<9+n<<" "<<9;
    }
    return 0;
}
