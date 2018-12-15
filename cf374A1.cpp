#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    int ctr=0;
    cin>>s;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(s[i]=='B'){
            ctr++;
        } else{
            if(ctr>0)
                ans.push_back(ctr);
            ctr=0;
        }
    }
    if(ctr>0){
        ans.push_back(ctr);
    }

    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
