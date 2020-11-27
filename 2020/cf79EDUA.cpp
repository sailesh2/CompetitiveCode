#include<bits/stdc++.h>

using namespace std;

bool three(int r, int b, int g){
        int div=min(r,min(b,g));
        r=r-div;
        b=b-div;
        g=g-div;

        if(r==0 && abs(b-g)<=1){
            return true;
        }else if(b==0 && abs(r-g)<=1){
            return true;
        }else if(g==0 && abs(r-b)<=1){
            return true;
        }else{
            return false;
        }
}

bool two(int r, int b, int g){
    int div = min(r,b);
    r=r-div;
    b=b-div;

    if(r==0 && (abs(g-b)<=1 || abs(g-b-1)<=1))
        return true;
    else if(b==0 && (abs(g-r)<=1 || abs(g-r-1)<=1))
        return true;
    else
        return false;
}

int main(){
    int t;
    cin>>t;
    int r,b,g;
    for(int i=0;i<t;i++){
        cin>>r>>b>>g;
        if(three(r,b,g) || two(r,g,b) || two(r,b,g) || two(b,g,r))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
