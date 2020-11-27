#include<bits/stdc++.h>

using namespace std;
int n,k;
int MAX=1000000009;

set<pair<int,int>> st;
set<pair<int,int>>::iterator stIt;

int odd(){
    int l=k/2+k%2;

    int has[200005]={0};
    int ctr=0,v;
    int taken=0;

    stIt = st.begin();
    while(ctr<l){

        if(stIt==st.end())
            break;
        int ind = stIt->second;
        if(ind-1>=0 && ind+1<n){
            if(has[ind-1]==0 && has[ind+1]==0){
                ctr++;
                v=stIt->first;
                has[ind]=1;
            }
        }
        else if(ind-1>=0){
            if(k<n || k%2!=0 || taken==0){
                if(has[ind-1]==0){
                    ctr++;
                    v=stIt->first;
                    has[ind]=1;
                    taken=1;
                }
            }
        }else if(ind+1<n){
            if(k<n || k%2!=0 || taken==0){
                if(has[ind+1]==0){
                    ctr++;
                    v=stIt->first;
                    has[ind]=1;
                    taken=1;
                }
            }
        }
        stIt++;
    }

    if(ctr==l)
        return v;
    else
        return MAX;
}

int even(){
    int l=k/2;

    int has[200005]={0};
    int ctr=0,v;
    stIt = st.begin();
    int taken=0;

    while(ctr<l){

        if(stIt==st.end())
            break;
        int ind = stIt->second;

        if(ind-1>=0 && ind+1<n){
            if(has[ind-1]==0 && has[ind+1]==0){
                ctr++;
                v=stIt->first;
                has[ind]=1;
            }
        }
        else if(ind-1>=0){
            if(k%2==0 && taken==0){
                if(has[ind-1]==0){
                    ctr++;
                    v=stIt->first;
                    has[ind]=1;
                    taken=1;
                }
            }
        }else if(ind+1<n){
            if(k%2==0 && taken==0){
                if(has[ind+1]==0){
                    ctr++;
                    v=stIt->first;
                    has[ind]=1;
                    taken=1;
                }
            }
        }

        stIt++;
    }

    if(ctr==l)
        return v;
    else
        return MAX;
}

int main(){
    int x;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
        st.insert(make_pair(x,i));
    }

    if(n==k){
        int maxie=0,maxio=0;
        for(int i=0;i<n;i++){
            if(i%2==0)
                maxie=max(maxie,arr[i]);
            else
                maxio=max(maxio,arr[i]);
        }
        cout<<min(maxio,maxie);
    }else
        cout<<min(odd(),even());
    return 0;
}
