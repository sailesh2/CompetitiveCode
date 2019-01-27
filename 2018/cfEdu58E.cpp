#include<bits/stdc++.h>
#define gc getchar

using namespace std;

inline long int lscan()
{
long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

int main(){
    long int q,maxi=0,maximini=0,l,b;
    char type;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>type;
        l=lscan();
        b=lscan();
        if(type=='+'){

            maxi=max(maxi,max(l,b));
            maximini=max(maximini,min(l,b));
        }else{
            if(maxi<=max(l,b) && maximini<=min(l,b))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
