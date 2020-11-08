#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b,c,d,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c>>d>>k;
        int x=(int)ceil((float)a/c);
        int y= (int)ceil((float)b/d);
        if(x+y<=k)
            cout<<x<<" "<<y<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}
