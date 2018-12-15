#include<bits/stdc++.h>

using namespace std;
string s;
int n;
bool isKDominant(int k){
    if(k==0)
        return false;
    int cnt,l,j;
    for(char i='a';i<='z';i++){
        cnt=0;
        for(j=0;j<k;j++){
            if(s[j]==i){
                cnt++;
            }
        }
        if(cnt>0){
            l=0;
            while(j<n){
                if(s[l]==i){
                    cnt--;
                }
                if(j<n){
                    if(s[j]==i)
                        cnt++;
                    if(cnt==0)
                        break;
                }
                j++;
                l++;
            }
        }
        if(cnt>0)
            break;
    }
    return cnt>0;
}
int binSear(){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<=n && !isKDominant(save+ctr)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+1;
}

int main(){
    cin>>s;
    n=s.length();
    cout<<binSear();
    return 0;
}
