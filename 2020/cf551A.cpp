#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t,s,d;
    cin>>n>>t;
    int mini;
    int save;
    for(int i=0;i<n;i++){
        cin>>s>>d;
        if(i==0){
            save=0;
         if(t<s){
                mini=s;
            }else{
                mini=s + ((int)ceil((float)(t-s)/d))*d;
            }
        }
        else{
            if(t<s){
                if(s<mini){
                    mini=s;
                    save=i;
                }
            }else{
                int k=(int)ceil((float)(t-s)/d);
                if(s+k*d<mini){
                    mini=s+k*d;
                    save=i;
                }
            }
        }
    }
    cout<<save+1;
    return 0;
}
