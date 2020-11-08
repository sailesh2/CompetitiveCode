#include<bits/stdc++.h>

using namespace std;

vector<int> permute(int* arr, int n){
    vector<int> ans;
    for(int i=0;i<n;i++)
        ans.push_back(1);
    set<int> has;
    for(int i=0;i<n;i++){
        if(has.count(i)==0){
            int c=0;
            vector<int> v;
            while(has.count(i)==0){
                has.insert(i);
                v.push_back(i);
                i=arr[i];
                c++;
            }
            for(int j=0;j<v.size();j++)
                ans[v[j]]=c;

        }
    }

    return ans;
}

int main(){
    int q;
    int n;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
            arr[j]--;
        }

        vector<int> ans = permute(arr,n);
        for(int j=0;j<n;j++){
            cout<<ans[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
