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
    int n,x;
    cin>>n;
    vector<int> arr;
    vector<pair<char,int> > ans;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    int brr[k];
    for(int i=0;i<k;i++){
        cin>>brr[i];
    }
    int ctr=0,ind=0;
    while(ctr<n-k){
        for(int i=0;i<n;i++){

            if(arr[i]<brr[ind]){
                if(i+1<arr.size() && arr[i]>arr[i+1]){
                    arr[i]=arr[i]+arr[i+1];
                    ans.push_back(make_pair('R',i+1));
                    arr.erase(arr.begin()+i+1);

                    if(arr[i]==brr[ind])
                        ind++;

                    break;
                }
            }
            if(arr[i]<brr[ind]){
                if(i-1>=0 && arr[i]>arr[i-1]){
                    arr[i]=arr[i]+arr[i-1];
                    ans.push_back(make_pair('L',i+1));
                    arr.erase(arr.begin()+i-1);
                    if(arr[i]==brr[ind])
                        ind++;

                    break;
                }
            }
        }
        ctr++;
    }
    if(ind==k){
        int cnt=0;
        for(int i=0;i<k;i++){
            if(arr[i]!=brr[i]){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<"YES\n";
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].second<<" "<<ans[i].first<<"\n";
            }
        } else{
            cout<<"NO";
        }
    } else{
        cout<<"NO";
    }

    return 0;
}
