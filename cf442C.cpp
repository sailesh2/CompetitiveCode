#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int i=n/2-1,j=n/2+1;
    vector<int> ans;
    ans.push_back(n/2);

    int cnt=0,d=0;
    while(i<j){
        if(cnt==0){
            if(j==n){
                cnt=1;
                if(n%2==0){
                    ans.push_back(i);
                    ans.push_back(i+1);
                    if(i+1==n/2)
                        d=1;
                    i=2;
                    j=n-2;
                }else{
                    i=1;
                    j=n-2;
                }
            }else{
                ans.push_back(i);
                ans.push_back(j);
                i--;
                j++;
            }
        }else{
            ans.push_back(i);
            ans.push_back(j);
            i++;
            j--;
        }
    }
    if(d==0)
        ans.push_back(n/2);

    cout<<ans.size()<<"\n";
    for(int k=0;k<ans.size();k++){
        cout<<ans[k]+1<<" ";
    }
    return 0;
}
