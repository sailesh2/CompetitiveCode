#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>s;

        int f=0;
        for(int j=0;j<n;j++){
            if(s[j]=='1')
                break;
            f++;
        }

        int r=0;
        for(int j=n-1;j>=0;j--){
            if(s[j]=='0')
                break;
            r++;
        }

        if(f+r<n){
            f++;
        }
        for(int j=0;j<f;j++)
            cout<<"0";
        for(int j=0;j<r;j++)
            cout<<"1";
        cout<<"\n";
    }
    return 0;
}
