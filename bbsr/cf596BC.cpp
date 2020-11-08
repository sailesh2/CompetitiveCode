#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,d,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>d;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        map<int,int> has;
        map<int,int>::iterator hasIt;
        int ctr=0,mini;
        for(int j=0;j<d;j++){
            hasIt=has.find(arr[j]);
            if(hasIt==has.end()){
                ctr++;
                has.insert(make_pair(arr[j],1));
            }else{
                int v=hasIt->second;
                has.erase(hasIt);
                has.insert(make_pair(arr[j],v+1));
            }
        }
        mini=ctr;
        for(int j=d;j<n;j++){
            hasIt=has.find(arr[j-d]);
            int v=hasIt->second;
            if(v==1){
                ctr--;
                has.erase(hasIt);
            }else{
                has.erase(hasIt);
                has.insert(make_pair(arr[j-d],v-1));
            }

            hasIt=has.find(arr[j]);
            if(hasIt==has.end()){
                ctr++;
                has.insert(make_pair(arr[j],1));
            }else{
                v=hasIt->second;
                has.erase(hasIt);
                has.insert(make_pair(arr[j],v+1));
            }
            mini=min(mini,ctr);
        }
        cout<<mini<<"\n";
    }
    return 0;
}
