#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,x,k,y;
    long long int v,v2,v3,v4;
    cin>>n>>x>>k;
    multiset<long long int> st;
    multiset<long long int>::iterator stItU;
    multiset<long long int>::iterator stItL;
    set<long long int> dupl;
    set<long long int>::iterator duIt;
    long long int ctr=0;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    /*if(k==0){
        for(int i=0;i<n;i++){
            y=arr[i];
            if(y%x!=0){
            st.insert(y);
            dupl.insert(y);
            }
        }
        for(duIt=dupl.begin();duIt!=dupl.end();duIt++){

            v=st.count(*duIt);
            ctr=ctr+(v*v);
        }
        cout<<ctr;
    }*/
    {
        for(int i=0;i<n;i++){
            y=arr[i];
            st.insert(y);
            v=(((y/x)*x)-k*x);
            v2=(((y/x)*x)-(k-1)*x);;
            stItU=st.upper_bound(v);
            stItL=st.lower_bound(v2);

            if(v==v2){
                ctr=ctr+distance(stItU,st.end());
            }else{
                //if(v2==y){

                //}
                //cout<<*stItU<<" "<<*stItL<<"--";
                //cout<<distance(stItU,stItL)<<"\n";
                if(st.count(v2)==0)
                    ctr=ctr+distance(stItU,stItL);
                else {
                    v3=(*stItL/x)*x;
                    v4=((long long int)ceil(((double)*stItU/x)))*x;

                    if((v3-v4)/x +1==k){
                    if(stItU==stItL){
                    dupl.insert(v2);
                    ctr=ctr+(distance(stItU,stItL)+1);
                    }else{
                    ctr=ctr+distance(stItU,stItL);
                    }
                    }
                }
            }
        }
        for(duIt=dupl.begin();duIt!=dupl.end();duIt++){

            v=st.count(*duIt);
            ctr=ctr+(v*(v-1));
        }
        cout<<ctr;
    }
    return 0;
}
