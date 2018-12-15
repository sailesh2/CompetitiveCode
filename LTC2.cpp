#include<bits/stdc++.h>

using namespace std;
#define gc getchar
string maxDiv6(string n){
    int ds=0;
    int l=n.length();
    int dig[l];
    for(int i=0;i<l;i++){
        ds=ds+(int)(n[i]-48);
        dig[i]=(int)(n[i]-48);
    }
    if(dig[l-1]%2==0){
        int save=-1,cnt=0;
        for(int i=0;i<l-1;i++){
            if((ds-dig[i])%3==0){
                save=i;
                if(dig[i+1]>dig[i]){
                    cnt=1;
                    break;
                }
            }
        }
        if(save==-1){
            if((ds-dig[l-1])%3==0 && dig[l-2]%2==0){
                save=l-1;
            }
        }

        if(save==-1){
            return "-1";
        }
        else{
            if(cnt==0){
               if((ds-dig[l-1])%3==0 && dig[l-2]%2==0){
                    save=l-1;
                }
            }
            string s="";
            for(int i=0;i<l;i++){
                if(save!=i)
                    s=s+n[i];
            }
            return s;
        }


    }else{
        if(dig[l-2]%2==0){
            if((ds-dig[l-1])%3!=0){
                return "-1";
            }else{
                string s="";
                for(int i=0;i<l-1;i++){
                    s=s+n[i];
                }
                return s;
            }
        }else{
            return "-1";
        }
    }
}

inline string sscan()
{
string n="";
char c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n+c;
c=gc();}
return n;
}
int main(){
    int t;
    string n;
    cin>>t;
    for(int i=0;i<t;i++){
        n=sscan();
        cout<<maxDiv6(n)<<"\n";
    }
    return 0;
}
