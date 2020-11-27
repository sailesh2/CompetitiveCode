#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    long long int s,i,e;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>s>>i>>e;
        long long int x=1+(long long int)floor(((double)(i+e-s))/2);
        if((i+e-s) < 0)
            x=0;
        if(e==0){
            if(s>i)
                cout<<"1\n";
            else
                cout<<"0\n";
        }else
            cout<<max(0LL,e-x+1)<<"\n";

    }
    return 0;
}
