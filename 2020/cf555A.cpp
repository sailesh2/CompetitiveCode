#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> rev;

    while(n>0){
        rev.push_back(n%10);
        n=n/10;
    }
    int sm=0;
    for(int i=0;i<rev.size()-1;i++){
        if(i>0)
        rev[i]=rev[i]+1;
        sm=sm+10-rev[i];
    }
    sm=sm+9;
    cout<<sm;
    return 0;
}
