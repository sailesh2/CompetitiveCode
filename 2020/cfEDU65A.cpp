#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    string s;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>s;
        int save=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='8'){
                save=i;
                break;
            }
        }

        if(save==-1 || (n-save)<11)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}
