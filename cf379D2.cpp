#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int indx[n],indy[n],x,y,kx,ky;
    char tool[n];
    cin>>kx>>ky;
    set<pair<long long int,long long int> > st;
    set<pair<long long int,long long int> >::iterator stit;
    for(int i=0;i<n;i++){
        cin>>tool[i]>>indx[i]>>indy[i];
    }
    int cnt=0;
    st.insert(make_pair(ky,-1));
    for(int i=0;i<n;i++){
        if(indx[i]==kx){
            st.insert(make_pair(indy[i],i));
        }
    }
    stit=st.find(make_pair(ky,-1));
    stit++;
    if(stit!=st.end()){
        if(tool[stit->second]!='B'){
            cnt=1;
        }
    }

    stit=st.find(make_pair(ky,-1));
    if(stit!=st.begin()){
        stit--;
        if(tool[stit->second]!='B'){
            cnt=1;
        }
    }

    st.clear();
    st.insert(make_pair(kx,-1));
    for(int i=0;i<n;i++){
        if(indy[i]==ky){
            st.insert(make_pair(indx[i],i));
        }
    }
    stit=st.find(make_pair(kx,-1));
    stit++;
    if(stit!=st.end()){
        if(tool[stit->second]!='B'){
            cnt=1;
        }
    }

    stit=st.find(make_pair(kx,-1));
    if(stit!=st.begin()){
        stit--;
        if(tool[stit->second]!='B'){
            cnt=1;
        }
    }

    st.clear();

    st.insert(make_pair(kx,-1));
    for(int i=0;i<n;i++){
        if(indx[i]+indy[i]==kx+ky){
            st.insert(make_pair(indx[i],i));
        }
    }
    stit=st.find(make_pair(kx,-1));
    stit++;
    if(stit!=st.end()){
        if(tool[stit->second]!='R'){
            cnt=1;
        }
    }

    stit=st.find(make_pair(kx,-1));
    if(stit!=st.begin()){
        stit--;
        if(tool[stit->second]!='R'){
            cnt=1;
        }
    }

    st.clear();

    st.insert(make_pair(kx,-1));
    for(int i=0;i<n;i++){
        if(indx[i]-indy[i]==kx-ky){
            st.insert(make_pair(indx[i],i));
        }
    }
    stit=st.find(make_pair(kx,-1));
    stit++;
    if(stit!=st.end()){
        if(tool[stit->second]!='R'){
            cnt=1;
        }
    }

    stit=st.find(make_pair(kx,-1));
    if(stit!=st.begin()){
        stit--;
        if(tool[stit->second]!='R'){
            cnt=1;
        }
    }

    st.clear();

     if(cnt==1){
        cout<<"YES";
    } else{
        cout<<"NO";
    }
    return 0;
}
