#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int l,t,j,k;
    long long int ctr=0,cnt;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        l=s.length();
        if(l==1){
            cout<<"0\n";
        }else if(l==2){
            if(s[0]==s[1]){
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }else{
            ctr=0;
            for(int j1=0;j1<l-1;j1++){
                if(s[j1]==s[j1+1])
                    ctr++;
            }
            j=0,k=2;
            while(k<l){
                if(s[k]!=s[k-1]){
                    if(s[k]==s[j]){
                        ctr++;
                    }
                    if(k-j-1>2){
                        cnt=k-j-1;
                        ctr=ctr+((cnt*(cnt+1))/2)-(2*cnt-1);
                    }
                    j=k-1;
                }
                k++;
            }
            if(j==0 && s[l-1]==s[j]){
                if(l>2)
                {
                    cnt=l;
                    ctr=ctr+((cnt*(cnt+1))/2)-(2*cnt-1);

                }
            }else{
                if(l-1-j>2)
                {
                    cnt=l-1-j;
                    ctr=ctr+((cnt*(cnt+1))/2)-(2*cnt-1);
                }
            }
            cout<<ctr<<"\n";
        }
    }
    return 0;
}
