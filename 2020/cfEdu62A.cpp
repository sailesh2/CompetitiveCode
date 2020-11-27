#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int maxi=1;
    int pages[n];
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int ctr=0;
    for(int i=1;i<=n;i++){
        maxi=max(maxi,pages[i-1]);
        if(maxi<=i){
            ctr++;
        }
    }
    cout<<ctr;
    return 0;
}
