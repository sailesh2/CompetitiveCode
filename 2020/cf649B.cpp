#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }

        int cnt=0;
        if(arr[0]>arr[1])
            cnt=1;
        int save=arr[0];
        vector<int> v;
        v.push_back(0);
        for(int j=2;j<n;j++){
            if(cnt==0){
                if(arr[j]<arr[j-1]){
                    cnt=1;
                    save=arr[j-1];
                    v.push_back(j-1);
                }
            }else{
                if(arr[j]>arr[j-1]){
                    cnt=0;
                    save=arr[j-1];

                    v.push_back(j-1);
                }
            }
        }

        if(save!=arr[n-1]){
            v.push_back(n-1);
        }
        cout<<v.size()<<"\n";
        for(int j=0;j<v.size();j++)
            cout<<arr[v[j]]<<" ";
        cout<<"\n";
    }
    return 0;
}
