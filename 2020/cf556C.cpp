#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ones=0;
    int twos=0;
    int tile;
    for(int i=0;i<n;i++){
        cin>>tile;
        if(tile==1)
            ones++;
        else
            twos++;
    }

    vector<int> ans;
    if(ones==0){
        for(int i=0;i<twos;i++){
            ans.push_back(2);
        }
    }else if(ones==1){
        if(twos>=1){
            ans.push_back(2);
            twos--;
        }
        ans.push_back(1);
        for(int i=0;i<twos;i++){
            ans.push_back(2);
        }
    }else if(ones==2){
        if(twos>=1){
            ans.push_back(2);
            twos--;
        }
        ans.push_back(1);

        for(int i=0;i<twos;i++){
            ans.push_back(2);
        }
        ans.push_back(1);

    }else{
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        for(int i=0;i<twos;i++){
            ans.push_back(2);
        }
        ones=ones-3;
        for(int i=0;i<ones;i++){
            ans.push_back(1);
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
