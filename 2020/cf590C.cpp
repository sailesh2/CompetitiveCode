#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n;
        cin>>n;
        string top,bottom;
        cin>>top>>bottom;

        int cnt=0;
        bool possible=true;
        for(int j=0;j<n;j++){
            if(cnt==0){
                if(top[j]=='1' || top[j]=='2'){
                    continue;
                }else{
                    cnt=1-cnt;
                    if(bottom[j]=='1' || bottom[j]=='2'){
                        possible=false;
                        break;
                    }
                }
            }else{
                if(bottom[j]=='1' || bottom[j]=='2'){
                    continue;
                }else{
                    cnt=1-cnt;
                    if(top[j]=='1' || top[j]=='2'){
                        possible=false;
                        break;
                    }
                }
            }
        }
       if(cnt==0)
            possible=false;
        if(possible)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
