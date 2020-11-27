#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        int maxi=max(a,b);
        int mini=min(a,b);

        cout<<min(mini,(a+b)/3)<<"\n";
    }
    return 0;
}
