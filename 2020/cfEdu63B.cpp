#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int ctr1=(n-11)/2;
    int ctr2=(n-11)/2;
    int pos1=-1;
    int pos2=-1;
    for(int i=0;i<n;i++){
        if(ctr1==0)
            break;
        if(s[i]=='8'){
            pos1=i;
            ctr1--;
        }
    }

    for(int i=0;i<n;i++){
        if(ctr2==0)
            break;
        if(s[i]!='8'){
            pos2=i;
            ctr2--;
        }
    }

    int finalP;
    if(pos1<pos2){
        finalP=pos2+1;
        for(int i=pos1+1;i<pos2;i++){
            if(s[i]=='8'){
                finalP=i;
                break;
            }
        }
    }else if(pos2<pos1){
        finalP=pos1+1;
        for(int i=pos2+1;i<pos1;i++){
            if(s[i]!='8'){
                finalP=i;
                break;
            }
        }
    }else{
        finalP=pos1+1;
    }
    if(s[finalP]=='8'){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
