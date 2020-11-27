#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> digRev;
    vector<int> dig;
    while(n>0){
        digRev.push_back(n%10);
        n=n/10;
    }
    long long int maxi=1,p;
    for(int i=digRev.size()-1;i>=0;i--){
        dig.push_back(digRev[i]);
        maxi=maxi*digRev[i];
    }


    for(int i=0;i<dig.size();i++){
        p=dig[i]-1;
        if(p<=0)
            p=1;
        for(int j=0;j<dig.size();j++){
            if(j<i){
                p=p*dig[j];
            }else if(j>i){
                p=p*9;
            }
        }
        maxi=max(maxi,p);
    }
    cout<<maxi;
    return 0;
}
