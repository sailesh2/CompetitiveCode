#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int x=0,y=0,ctr=0,cnt=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='U'){
            if(cnt==0)
                ctr++;

            cnt=-1;

            y=y+1;
            if(x==y){
                cnt=0;
            }

        }else{
            if(cnt==1)
                ctr++;
            cnt=-1;
            x=x+1;
            if(x==y){
                cnt=1;
            }
        }
    }
    cout<<ctr;
    return 0;
}
