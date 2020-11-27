#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,x;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>n>>x;
        cin>>s;
        int ctrIn=0;
        int c=0;

        for(int j=0;j<n;j++){
            if(s[j]=='0'){
                c++;
            }else{
                c--;
            }
        }
        int pre=0,cnt=0;
            if(c==0){
                if(x-pre==0){
                    cnt=1;
                }
            }else{
                if((x-pre)%c==0 && (x-pre)/c==0){
                    ctrIn++;
                }
            }
        for(int j=0;j<n;j++){
             if(s[j]=='0'){
                pre++;
            }else{
                pre--;
            }
            if(c==0){
                if(x-pre==0){
                    cnt=1;
                }
            }else{
                if((x-pre)%c==0 && (x-pre)/c>=0){
                    ctrIn++;
                }
            }
        }
        if(cnt==1)
            cout<<"-1\n";
        else
            cout<<ctrIn<<"\n";
    }

    return 0;
}
