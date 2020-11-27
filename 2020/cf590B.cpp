#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int que[n];
    int f=-1,r=-1;
    int a;
    set<int> has;
    for(int i=0;i<n;i++){
        cin>>a;
        if(has.count(a)==0){
            has.insert(a);
            if(r-f<k){
                que[++r]=a;
            }else{
                has.erase(has.find(que[++f]));
                que[++r]=a;
            }
        }
    }
    cout<<r-f<<"\n";
    for(int i=r;i>f;i--){
        cout<<que[i]<<" ";
    }
    return 0;
}
