#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ans;
    ans.push_back(n/2);

    for(int i=n/2-1;i>=0;i--){
        ans.push_back(i);
    }
    for(int i=1;i<n/2;i++){
        ans.push_back(i);
    }

    for(int j=n/2+1;j<n;j++){
        ans.push_back(j);
    }

    for(int j=n-2;j>n/2;j--){
        ans.push_back(j);
    }
    ans.push_back(n/2);

    cout<<ans.size()<<"\n";
    for(int k=0;k<ans.size();k++){
        cout<<ans[k]+1<<" ";
    }
    return 0;
}
