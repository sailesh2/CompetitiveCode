#include<bits/stdc++.h>
#define gc getchar

using namespace std;

int k;

inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
set<int> online;
int isDisplayed(int id){

    vector<int> isVisible;
    int noOfOnline = online.size();
    set<int>::iterator onlineIt;
    int miniR=min(k,noOfOnline);
    onlineIt=online.end();

    int cnt=0;
    for(int i=0;i<miniR;i++){
        onlineIt--;
        if(*onlineIt==id){
            cnt=1;
            break;
        }
    }
    return cnt;

}
int main(){
    int n,q;
    cin>>n>>k>>q;
    int t[n];
    for(int i=0;i<n;i++){
        t[i]=lscan();
    }
    int type,id;
    for(int i=0;i<q;i++){
        type=lscan();
        id=lscan();
        if(type==1){
            online.insert(t[id-1]);
        } else{
            if(isDisplayed(t[id-1])==1){
                printf("YES\n");
            } else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
