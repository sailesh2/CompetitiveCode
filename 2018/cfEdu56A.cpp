#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x;
        if(x%2==0){
            cout<<x/2<<"\n";
        }else{
            cout<<(x-2)/2+1<<"\n";
        }
    }
    return 0;
}
