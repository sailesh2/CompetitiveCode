#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,k;
    cin>>n>>m>>k;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    multiset<long long int> st;
    multiset<long long int>::iterator stIt;
    long long int sm=0;
    long long int parts=0,strt=n;
    for(int i=0;i<n;i++){
        if(i%m==0){
            parts++;
        }
        if(parts==k+1){
            strt=i;
          break;
        }
        st.insert(arr[i]);
        sm=sm+arr[i];
    }
    long long int endi=n-1;


    long long int ind,cnt=0,v,c;
    long long int save=strt-1;
    long long int maxi=sm;
    vector<long long int> ms;
    map<long long int, long long int> mins;
    map<long long int, long long int>::iterator minsIt;
    for(int i=strt;i<=endi;i++){
        st.insert(arr[i]);
        stIt = st.begin();
        v=*stIt;
        ms.push_back(v);
        st.erase(stIt);
        sm=sm-v+arr[i];

    }

    for(int i=strt;i<=endi;i++){
        v=ms[i-strt];
        minsIt = mins.find(v);
        c=0;
        if(minsIt!=mins.end()){
            c=minsIt->second;
            mins.erase(minsIt);
        }
        c++;
        mins.insert(make_pair(v,c));
    }

    vector<long long int> partIndex;
    partIndex.push_back(0);
    long long int ctr=endi-strt+1;
    parts=0;
    for(int i=0;i<n;i++){
        minsIt=mins.find(arr[i]);

        if(ctr>0 && minsIt!=mins.end()){
            c=minsIt->second;
            c--;
            mins.erase(minsIt);
            cnt++;
            ctr--;
            if(c>0)
                mins.insert(make_pair(arr[i],c));
        }
        if(i-partIndex[partIndex.size()-1]==m+cnt){
            partIndex.push_back(i);
            parts++;
            cnt=0;
        }
        if(parts==k-1)
            break;
    }

    cout<<sm<<"\n";
    for(int i=1;i<partIndex.size();i++){
        cout<<partIndex[i]<<" ";
    }
    return 0;
}
