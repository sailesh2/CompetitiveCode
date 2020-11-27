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
                st[arr[j]]=1;
            }
        }

        if(dctr>k){
            cout<<"-1\n";
        }else{

            for(int j=1;d.size()<k && j<=n;j++){
                if(st[j]==0){
                    d.push_back(j);
                }
            }
            sort(d.begin(),d.end());

            dctr=d.size();
            int j1=0;
            vector<int> ans;
            int ctr=0;
            while(j1<n){
                if(d[ctr]==arr[j1]){
                    ans.push_back(arr[j1]);
                    j1++;
                }else{
                    ans.push_back(d[ctr]);
                }
                ctr=(ctr+1)%dctr;
            }

            cout<<ans.size()<<"\n";
            for(int j=0;j<ans.size();j++)
                cout<<ans[j]<<" ";
            cout<<"\n";

        }
    }
    return 0;
}
