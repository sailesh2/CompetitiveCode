#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    set<int> st;
    set<int> taken;
    vector<int> days;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            if(st.count(arr[i])>0){
                cnt=1;
                break;
            }
            if(taken.count(arr[i])>0){
                cnt=1;
                break;
            }
            st.insert(arr[i]);
        }else{
            if(st.count(-1*arr[i])==0){
                cnt=1;
                break;
            }
            if(taken.count(-1*arr[i])>0){
                cnt=1;
                break;
            }
            st.erase(st.find(-1*arr[i]));
            taken.insert(-1*arr[i]);
        }

        if(st.size()==0){
            days.push_back(taken.size());
            st.clear();
            taken.clear();
        }
    }

    if(st.size()>0){
        cnt=1;
    }

    if(cnt==1){
        cout<<"-1";
    }else{
        cout<<days.size()<<"\n";
        for(int i=0;i<days.size();i++)
            cout<<2*days[i]<<" ";
    }
    return 0;
}
