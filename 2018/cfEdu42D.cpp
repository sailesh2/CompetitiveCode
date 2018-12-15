#include<bits/stdc++.h>
#define gc getchar

using namespace std;

inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

bool fun(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

vector<int> mergeVec(vector<int> vec1,vector<int> vec2){
    int i=0,j=0;
    vector<int> vec;
    while(i<vec1.size() && j<vec2.size()){
        if(vec1[i]<vec2[j]){
            vec.push_back(vec1[i]);
            i++;
        }else{
            vec.push_back(vec2[j]);
            j++;
        }
    }
    while(i<vec1.size()){
        vec.push_back(vec1[i]);
        i++;
    }
    while(j<vec2.size()){
        vec.push_back(vec2[j]);
        j++;
    }
    return vec;
}
int main(){
    int n;
    n=lscan();
    int arr[n];
    set<long long int> st;
    set<long long int>::iterator stIt;

    map<long long int,vector<int> > lastPos;
    map<long long int,vector<int> >::iterator lastPosIt;
    map<long long int,vector<int> >::iterator lastPosIt2;

    long long int v;
    for(int i=0;i<n;i++){
        arr[i]=lscan();
        st.insert(arr[i]);
        lastPosIt = lastPos.find(arr[i]);
        vector<int> vec;
        if(lastPosIt != lastPos.end()){
            vec=lastPosIt->second;
            lastPos.erase(lastPosIt);
        }
        vec.push_back(i);
        lastPos.insert(make_pair(arr[i],vec));
    }
    vector<pair<long long int,int> > ans;
    while(1){
        stIt = st.begin();
        if(stIt!=st.end()){
            v=*stIt;
            lastPosIt = lastPos.find(v);
            vector<int> vec,vec2,vec3;
            vec = lastPosIt->second;
            lastPosIt2 = lastPos.find(2*v);
            if(lastPosIt2!=lastPos.end()){
                vec2 = lastPosIt2->second;
                lastPos.erase(lastPosIt2);
            }
            for(int i=0;i<vec.size();i++){
                if(i+1<vec.size()){
                    vec3.push_back(vec[i+1]);
                    i++;
                }
            }
            vec2=mergeVec(vec2,vec3);
            if(vec2.size()>0){
                //sort(vec2.begin(),vec2.end());
                lastPos.insert(make_pair(2*v,vec2));
                st.insert(2*v);
            }
            if((vec.size())%2==1){
                ans.push_back(make_pair(v,vec[vec.size()-1]));
            }
            st.erase(stIt);
        }
        else{
            break;
        }
    }
    sort(ans.begin(),ans.end(),fun);
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" ";
    }
    return 0;
}
