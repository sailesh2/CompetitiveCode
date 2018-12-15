#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int a,b,x,y;
    cin>>n>>a>>b;
    int cnt=0;
    for(int i=0;i<=n;i++){
        if(n-(a*i) <0){
            cnt=1;
            break;
        }
        if((n-a*i)%b==0){
            y=((n-a*i)/b);
            x=i;
            break;
        }
    }
    if(cnt==0){
        cout<<"YES\n";
        cout<<x<<" "<<y;
    }else{
        cout<<"NO";
    }
    return 0;
}
