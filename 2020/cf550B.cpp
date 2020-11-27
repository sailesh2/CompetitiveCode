#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long int> even;
    vector<long long int> odd;
    long long int c;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c%2==0){
            even.push_back(c);
        }else{
            odd.push_back(c);
        }
    }
    long long int sm=0;
    if(even.size()<=odd.size()){
        int l=odd.size()-even.size()-1;
        sort(odd.begin(),odd.end());
        for(int i=0;i<l;i++){
            sm=sm+odd[i];
        }
    }else{
        int l=even.size()-odd.size()-1;
        sort(even.begin(),even.end());
        for(int i=0;i<l;i++){
            sm=sm+even[i];
        }
    }
    cout<<sm;
    return 0;
}
