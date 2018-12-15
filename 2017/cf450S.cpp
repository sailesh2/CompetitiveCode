#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int x,y;
    int pos=0,neg=0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(x<0){
            neg++;
        }else{
            pos++;
        }
    }
    if(pos<=1 || neg<=1){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
