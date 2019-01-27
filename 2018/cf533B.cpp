#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int ctr=0,maxi=0,cnt;
    for(char d = 'a' ; d<='z'; d++){
        ctr=0;
        for(int i=0;i<n;i++){
            if(s[i]==d){
                int j=i;
                cnt=0;
                while(j<n && cnt<k){
                    if(s[j]!=d)
                        break;
                    j++;
                    cnt++;
                }
                if(cnt==k)
                    ctr++;
                i=j-1;
            }
        }
        maxi=max(maxi,ctr);
    }
    cout<<maxi;
    return 0;
}
