#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[6];
    arr[0]=4;
    arr[1]=8;
    arr[2]=16;
    arr[3]=15;
    arr[4]=23;
    arr[5]=42;

    map<pair<int,int>,vector<int> > mp;
    map<pair<int,int>,vector<int> >::iterator mpIt;

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i!=j){
                for(int k=0;k<6;k++){
                    if(i!=k && j!=k){
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[k]);
                        mp.insert(make_pair(make_pair(arr[i]*arr[j],arr[j]*arr[k]),v));
                    }
                }
            }
        }
    }
    vector<int> ans;
    int x,y;
    cout<<"? 1 2\n";
    fflush(stdout);
    cin>>x;
    if(x!=0){
        cout<<"? 2 3\n";
        fflush(stdout);
        cin>>y;
        if(y!=0){
            mpIt=mp.find(make_pair(x,y));
            if(mpIt!=mp.end()){
                vector<int> v=mpIt->second;
                ans.push_back(v[0]);
                ans.push_back(v[1]);
                ans.push_back(v[2]);
            }
        }
    }
    if(y!=0){
        cout<<"? 4 5\n";
        fflush(stdout);
        cin>>x;
        if(x!=0){
            cout<<"? 5 6\n";
            fflush(stdout);
            cin>>y;
            if(y!=0){
                mpIt=mp.find(make_pair(x,y));
                if(mpIt!=mp.end()){
                    vector<int> v=mpIt->second;
                    ans.push_back(v[0]);
                    ans.push_back(v[1]);
                    ans.push_back(v[2]);
                }
            }
        }
    }

    if(y!=0){
        cout<<"! ";
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    }

    return 0;
}
