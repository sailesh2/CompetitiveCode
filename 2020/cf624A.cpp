#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(a==b)
            cout<<"0\n";
        else if(a<b){
            if((b-a)%2==0)
                cout<<"2\n";
            else
                cout<<"1\n";
        }else{
            if((b-a)%2!=0)
                cout<<"2\n";
            else
                cout<<"1\n";
        }
    }
    return 0;
}
