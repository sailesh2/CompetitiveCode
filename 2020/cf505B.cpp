#include<bits/stdc++.h>
#define gc getchar

using namespace std;

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}


long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
    int n;
    n=lscan();
    long long int a,b;
    long long int g=0,g2=0;
    vector<pair<long long int,long long int> > v;
    for(int i=0;i<n;i++){
        a=lscan();
        b=lscan();
        v.push_back(make_pair(a,b));
        g2=gcd(a,b);
        g=gcd((a*b)/g2,g);
    }
    if(g==1){
        cout<<"-1";
    }else{
        int cnt=-1;
        for(int i=0;i<n;i++){
            if(v[i].first%g!=0 && v[i].second%g!=0){
                cnt=i;
                break;
            }
        }
        if(cnt==-1)
        cout<<g;
        else{
            int save=cnt;
            int cnt2=0;
            for(int i=0;i<n;i++){
                if(v[i].first%v[save].first!=0 && v[i].second%v[save].first!=0){
                    cnt2=1;
                    break;
                }
            }
            int cnt3=0;
            for(int i=0;i<n;i++){
                if(v[i].first%v[save].second!=0 && v[i].second%v[save].second!=0){
                    cnt3=1;
                    break;
                }
            }
            if(cnt2==0 || cnt3==0){
                if(cnt2==0)
                cout<<v[save].first;
                else
                cout<<v[save].second;
            }else{
                cout<<"-1";
            }
        }
    }
    return 0;
}
