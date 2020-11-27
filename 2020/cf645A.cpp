#include<bits/stdc++.h>

using namespace std;

int lights(int n, int m){
    if(n%2==0){
        return (n/2)*m;
    }else{
        return (n/2)*m + m/2+m%2;
    }
}

int main(){
    int t,n,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        cout<<lights(n,m)<<"\n";
    }

    return 0;
}
