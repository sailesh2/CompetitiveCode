#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<pair<long long int,long long int> > ans;
    long long int k,diff,newv;
    for(int i=n-1;i>=0;i--){
        k=(arr[i]-i)/n;
        if((arr[i]-i)%n!=0)
            k++;
        newv=n*k+i;
        diff = newv - arr[i];
        if(diff>0){
            ans.push_back(make_pair(i+1,diff));
            for(int j=0;j<=i;j++){
                arr[j]=arr[j]+diff;
            }
        }
    }
    cout<<ans.size()+1<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<"1 "<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    cout<<"2 "<<n<<" "<<n;
    return 0;
}
