#include<bits/stdc++.h>

using namespace std;

bool isEqual(string a, string b){
    return a[0]==b[0] && a[1]==b[1] && a[2]==b[2] && a[3]==b[3];
}

int main(){
    int t,n;
    cin>>t;
    int cnt,ctr;
    for(int i=0;i<t;i++){
        cin>>n;
        string p[n];
        ctr=0;
        for(int j=0;j<n;j++){
            cin>>p[j];
        }
        for(int j=0;j<n;j++){
            cnt=0;
            for(int k=0;k<n;k++){
                if(j!=k){
                    if(isEqual(p[j],p[k])){
                        ctr++;
                        cnt=1;
                        break;
                    }
                }
            }
            if(cnt==1){
                for(char ch='0';ch<='9';ch++){
                    p[j][0]=ch;
                    cnt=0;
                    for(int k=0;k<n;k++){
                        if(j!=k){
                            if(isEqual(p[j],p[k])){
                                cnt=1;
                                break;
                            }
                        }
                    }
                    if(cnt==0)
                        break;
                }
            }
        }
        cout<<ctr<<"\n";
        for(int j=0;j<n;j++)
            cout<<p[j]<<"\n";
    }
    return 0;
}
