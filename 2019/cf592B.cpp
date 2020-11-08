#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        string s;
        cin>>n>>s;
        int f=-1,l=-1;
        for(int j=0;j<n;j++){
            if(s[j]=='1'){
                if(f==-1){
                    f=j;
                }
                l=j+1;
            }
        }
        if(f==-1){
            cout<<n<<"\n";
        }else{
            cout<<2*max(n-f,l)<<"\n";
        }
    }
    return 0;
}
