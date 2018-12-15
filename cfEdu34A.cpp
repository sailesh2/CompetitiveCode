#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,cnt,x,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        cnt=0;
        for(int a=0;a<=200;a++){
            b=x-(3*a);
            if(b<0){
                break;
            }
            if(b%7==0 && b/7 >=0){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}
