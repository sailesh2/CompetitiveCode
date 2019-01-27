#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    long long int hits[n];
    string s;
    for(int i=0;i<n;i++){
        cin>>hits[i];
    }
    cin>>s;
    multiset<long long int> hitCount;
    multiset<long long int>::iterator hitCountIt;

    char prev = '0';
    long long int ctr=0;

    long long int sm=0;
    for(int i=0;i<n;i++){
        if(s[i]==prev){
            if(ctr==k){
                hitCountIt = hitCount.begin();
                if(hits[i]>*hitCountIt){
                    sm=sm-*hitCountIt;
                    hitCount.erase(hitCountIt);
                    hitCount.insert(hits[i]);
                    sm=sm+hits[i];
                }
            }else{
                sm=sm+hits[i];
                hitCount.insert(hits[i]);
                ctr++;
            }
        }else{
            ctr=1;
            hitCount.clear();
            prev=s[i];
            hitCount.insert(hits[i]);
            sm=sm+hits[i];
        }
    }

    cout<<sm;

    return 0;
}
