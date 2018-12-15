#include<bits/stdc++.h>

using namespace std;

int neg(int orig){

    int origDigs[11]={0};
    int k1=0;
    while(orig>0){
        origDigs[k1]=1-orig%2;
        orig=orig/2;
        k1++;
    }
    int p=1;
    int ans=0;
    for(int i=0;i<k1;i++){
        ans=ans+p*origDigs[i];
        p=p*2;
    }
    return ans;
}

int main(){
    int n;
    char c;
    int curr;
    cin>>n;
    int x,p=0;
    for(int i=0;i<n;i++){
        cin>>c>>curr;
        if(c=='|'){
            if(i==0){
                x=curr;
            }else{
                x=x | curr;
            }
        } else if(c=='&'){
            if(i==0){
                x=curr;
            }else{
                x=x & curr;
            }
        } else{
            if(i==0){
                x=neg(curr);
                p=1;
            }else{
                x=neg(x | curr);
                p=1-p;
            }
        }
    }
    if(p==1){
        cout<<"2\n";
        cout<<"0 ^\n";
        cout<<"| "<<x;
    }else{
        cout<<"1\n";
        cout<<"& "<<x;

    }
    return 0;
}
