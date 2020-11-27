#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,l,r,d,u;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        int n=s.length();
        l=0;
        r=0;
        u=0;
        d=0;
        for(int j=0;j<n;j++){
            if(s[j]=='U')
                u++;
            if(s[j]=='D')
                d++;
            if(s[j]=='L')
                l++;
            if(s[j]=='R')
                r++;
        }
        int minH=min(l,r);
        int minV=min(u,d);
        int minSteps=(minH+minV)*2;
        if(minSteps>=1 && minH>=1 && minV>=1){
            cout<<minSteps<<"\n";
            for(int j=0;j<minV;j++){
                cout<<"U";
            }
            for(int j=0;j<minH;j++){
                cout<<"R";
            }
            for(int j=0;j<minV;j++){
                cout<<"D";
            }
            for(int j=0;j<minH;j++){
                cout<<"L";
            }
        }else if(u>=1 && d>=1){
            cout<<"2\nUD";
        }else if(l>=1 && r>=1){
            cout<<"2\nLR";
        }else{
            cout<<"0\n";
        }
        cout<<"\n";
    }
    return 0;
}
