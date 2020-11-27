#include<bits/stdc++.h>

using namespace std;

int main(){
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;

    int s = max(max(max(x1,x2),x3),x4);
    if(s==x1){
        cout<<s-x2<<" "<<s-x3<<" "<<s-x4;
    }else if(s==x2){
        cout<<s-x1<<" "<<s-x3<<" "<<s-x4;

    }else if(s==x3){
        cout<<s-x1<<" "<<s-x2<<" "<<s-x4;

    }else{
        cout<<s-x2<<" "<<s-x3<<" "<<s-x1;

    }
    return 0;
}
