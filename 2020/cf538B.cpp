#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,k;
    cin>>n>>m>>k;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<pair<long long int, multiset<long long int> > > vs;
    multiset<long long int> st;
    multiset<long long int>::iterator stIt;
    long long int sm=0;
    long long int parts=0,strt;
    for(int i=0;i<n;i++){
        if(i%m==0){
            parts++;
        }
        if(parts==k){
            strt=i;
          break;
        }
        st.insert(arr[i]);
         if((i+1)%m==0){
            vs.push_back(make_pair(i+1-m,st));
            st.clear();
         }
        sm=sm+arr[i];
    }
    long long int endi=n-m-1;
    for(int i=n-1;i>=n-m;i--){
        sm=sm+arr[i];
    }

    long long int ind,cnt,v,last;
    long long int saveM;
    long long int mini;
    for(int i=strt;i<=endi;i++){
        mini=1000000009;
        for(int j=0;j<vs.size();j++){
            st=vs[j].second;
            stIt=st.begin();
            if(*stIt < mini){
                mini=*stIt;
                saveM = j;
            }
        }
       // cout<<i<<" "<<mini<<" "<<saveM<<"\n";

        if(arr[i]>=mini){
            st=vs[saveM].second;
            st.erase(mini);
            vs[saveM].second=st;
            for(int j=saveM;j<vs.size()-1;j++){
                st=vs[j].second;
                ind=vs[j+1].first;
                v=arr[ind];
                st.insert(v);
                vs[j].second=st;

                st=vs[j+1].second;
                st.erase(v);
                vs[j+1].second=st;
                vs[j+1].first=ind+1;
            }
            st=vs[vs.size()-1].second;
            st.insert(arr[i]);
            vs[vs.size()-1].second=st;

            sm=sm+arr[i]-mini;

            last=i;
        }else{
            break;
        }

    }


    cout<<sm<<"\n";
    for(int i=1;i<vs.size();i++){
        cout<<vs[i].first<<" ";
    }
    cout<<last+1;
    return 0;
}
