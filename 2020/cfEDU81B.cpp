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
        if(c==x)
            ctrIn++;
        for(int j=0;j<n;j++){
            if(s[j]=='0'){
                c++;
            }else{
                c--;
            }
            if(c==x)
                ctrIn++;
        }
        if(x>=c){
            if(c==0 && x==0)
            cout<<"-1\n";
            else if((c<=0 && x>=0) || (c>=0 && x<=0)){
                if(c==0)
                    cout<<ctrIn<<"\n";
                else{
                    int comp=c;
                    for(int j=0;j<n;j++){
                    if(s[j]=='0'){
                        comp++;
                    }else{
                        comp--;
                    }
                    if(comp==x)
                        ctrIn++;
                }
                    for(int j=n-1;j>=0;j--){
                        if(s[j]=='0'){
                            comp--;
                        }else{
                            comp++;
                        }
                        if(comp==x)
                            ctrIn++;
                    }
                    cout<<ctrIn<<"\n";
                }
            }
            else {
                int comp=c*(x/c);
                if(comp==x && x/c>1)
                    ctrIn++;
                for(int j=0;j<n;j++){
                    if(s[j]=='0'){
                        comp++;
                    }else{
                        comp--;
                    }
                    if(comp==x)
                        ctrIn++;
                }
                comp=c*(x/c);
                for(int j=n-1;j>=0;j--){
                    if(s[j]=='0'){
                        comp--;
                    }else{
                        comp++;
                    }
                    if(comp==x)
                        ctrIn++;
                }
                cout<<ctrIn<<"\n";
            }
        }else{
            cout<<ctrIn<<"\n";
        }
    }

    return 0;
}
