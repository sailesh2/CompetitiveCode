#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,n;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n;
        if(n==2)
            cout<<"2"<<"\n";
        else
            cout<<n%2<<"\n";
    }
    return 0;
}
