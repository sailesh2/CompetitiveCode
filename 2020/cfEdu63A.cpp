#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int ch[300]={0};
    int cnt=0;
    int savei=0,savej=0;
    for(int i=n-1;i>=0;i--){

        for(int j=(int)s[i]-1;j>=(int)'a';j--){
            if(ch[j]>0){
            cnt=1;
            savei=i+1;
            savej=ch[j];
            break;
            }
        }
        if(cnt==1)
            break;
        ch[(int)s[i]]=i+1;
    }
    if(cnt==0){
        cout<<"NO";
    }else{
        cout<<"YES\n";
        cout<<savei<<" "<<savej;
    }
    return 0;
}
