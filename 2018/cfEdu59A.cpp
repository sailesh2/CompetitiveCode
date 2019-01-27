#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,n;
    cin>>q;
    string s;
    for(int i=0;i<q;i++){
        cin>>n;
        cin>>s;
        if(n==2){
            if(s[1]>s[0]){
                cout<<"YES\n";
                cout<<"2\n";
                cout<<s[0]<<" "<<s[1]<<"\n";
            }else{
                cout<<"NO\n";
            }
        }else{
            cout<<"YES\n";
            cout<<"2\n";
            cout<<s[0]<<" ";
            for(int j=1;j<n;j++){
                cout<<s[j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
