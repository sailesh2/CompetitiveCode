#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b,c,r;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c>>r;
        int left=c-r;
        int right=c+r;

        int mini=min(a,b);
        int maxi=max(a,b);
        a=mini;
        b=maxi;
        if(a<=left && b>=right){
            int d=left-a+b-right;
            cout<<d<<"\n";
        }else if(left>=a && left<=b){
           int d=left-a;
            cout<<d<<"\n";

        }else if(right>=a && right<=b){
           int d=b-right;
            cout<<d<<"\n";

        }else if(a>left && b<right){
            cout<<"0\n";
        }else{
            cout<<b-a<<"\n";
        }
    }
    return 0;
}
