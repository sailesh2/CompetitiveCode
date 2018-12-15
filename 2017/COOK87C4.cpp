#include<bits/stdc++.h>

#define gc getchar
using namespace std;


long long int binSear(long long int cost){
    long long int ctr=1;
    long long int save=0;
    long long int save2=0;

    while(1){
        while((save+ctr)*(save+ctr)<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save;
}


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


int main(){
    int t;
    long long int y,ctr,b,c;
    map<long long int,long long int> has;
    map<long long int,long long int>::iterator hasIt;
    cin>>t;
    for(int i=0;i<t;i++){
        y=lscan();
        ctr=0;
        b=1;
        while(b<=700){
            if(y-b<=0)
                break;
            hasIt=has.find(y-b);
            if(hasIt!=has.end()){
                ctr=ctr+hasIt->second;
            }else{
                c=binSear(y-b);
                ctr=ctr+c;
                has.insert(make_pair(y-b,c));
            }
            b=b+1;
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
