#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,p,q,k;
    vector<long long int> ans;
    cin>>n;
    for(long long int i = 1;i*i<=n;i++){
        if(n%i==0){
            p=i;
            q=n/i;
            if(p!=q){
                k=n/p;
                ans.push_back(k+(k*(k-1)*p)/2);


                k=n/q;
                ans.push_back(k+(k*(k-1)*q)/2);
            }else{
                k=n/p;
                ans.push_back(k+(k*(k-1)*p)/2);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
