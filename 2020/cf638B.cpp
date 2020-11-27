#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        int arr[n];
        int st[105]={0};
        int dctr=0;
        vector<int> d;
        for(int j=0;j<n;j++){
            cin>>arr[j];
            if(st[arr[j]]==0){
                dctr++;
                d.push_back(arr[j]);
                st[arr[j]]++;
            }
        }

        if(dctr>k){
            cout<<"-1\n";
        }else{

        sort(d.begin(),d.end());
        int j1=0,j2=k;
        vector<int> ans;
        for(int j=0;j<k;j++)
            ans.push_back(arr[j]);

        while(j2<n && ans.size()<=10002){
            if(ans[j1]==arr[j2]){
                ans.push_back(arr[j2]);
                j2++;
                j1++;
            }else{
                ans.push_back(ans[j1]);
                j1++;
            }
        }

        if(ans.size()>10000){
            cout<<"-1\n";
        }else{
            cout<<ans.size()<<"\n";
            for(int j=0;j<ans.size();j++)
                cout<<ans[j]<<" ";
            cout<<"\n";
        }
        }
    }
    return 0;
}
