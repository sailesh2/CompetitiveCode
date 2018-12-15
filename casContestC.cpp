#include<bits/stdc++.h>

using namespace std;
set<int> arr[200005];

int fun(int v, int ind,int limit){
    int a;
    v=v-2;
    if(ind>limit)
        return 0;
    if(v==0)
        return 1;
    else if(v==1)
        return 2;
    set<int>::iterator vIt;

    vIt=arr[ind].find(v);
    if(vIt==arr[ind].end())
        return 0;
    arr[ind].erase(vIt);
    a=fun(v,ind+1,limit);
    if(a==0){
        return 0;
    }else{
        return a+2;
    }
}
int main(){
    int n,m,maxi=1,v1;
    cin>>n>>m;
    int a,b,lt;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[a].insert(b-a);
        arr[b].insert(a-b);
    }
    set<int>::iterator sIt;
    for(int i=1;i<=n;i++){
        for(sIt=arr[i].begin();sIt!=arr[i].end();sIt++){

            lt=*sIt;
            if(lt>1){
            lt=(lt+2*i)/2;
            v1=fun(*sIt,i+1,lt);
            if(v1>0)
                v1=v1+2;
            maxi=max(maxi,v1);
            }else if(lt==1 && i<n-1){
                maxi=max(maxi,2);
            }
        }
    }
    cout<<maxi;
    return 0;
}
