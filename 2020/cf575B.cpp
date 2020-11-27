#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    int n,k;
    for(int i=0;i<q;i++){
        cin>>n>>k;
        int arr[n];
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2!=0){
                v.push_back(i+1);
            }
        }
        int odds=v.size();
        if(odds-k>=0 && (odds-k)%2==0){
            cout<<"YES\n";
            for(int i=0;i<k-1;i++){
                cout<<v[i]<<" ";
            }
            cout<<n<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
