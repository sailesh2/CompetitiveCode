#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,x;
    cin>>n>>k;
    set<int> que;
    set<int>::iterator queIt;
    for(int i=0;i<n;i++){
        cin>>x;
        que.insert(x);
    }
    int sm=0;
    for(int i=0;i<k;i++){
        queIt = que.begin();
        if(queIt == que.end()){
            cout<<"0\n";
        }else{
            cout<<*queIt - sm<<"\n";
            sm=*queIt;
            que.erase(queIt);
        }
    }
    return 0;
}
