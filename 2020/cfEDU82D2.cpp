#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,m,n,x;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>m>>n;
        long long int s=0;
        long long int arr[n];
        for(long long int j=0;j<n;j++){
            cin>>arr[j];
        }
        sort(arr,arr+n);
        long long int cnt=0,ctr=0;
        vector<pair<long long int,long long int> > notPossible;
        for(long long int j=0;j<n;j++){
            if(s<arr[j]){
                notPossible.push_back(make_pair(s+1,arr[j]-1));
            }
            s=s+arr[j];
            if(s>=m){
                cnt=1;
                for(long long int k=0;k<notPossible.size();k++){
                    if(m>=notPossible[k].first && m<=notPossible[k].second){
                        long long int v=notPossible[k].second+1;
                        while(v>0){
                            if(v+notPossible[k].first-1 <=m){
                                break;
                            }
                            ctr++;
                            v=v/2;
                        }
                        break;
                    }
                }
                break;
            }
        }
        if(cnt==0){
            cout<<"-1\n";
        }else{
            cout<<ctr<<"\n";
        }
    }
    return 0;
}
