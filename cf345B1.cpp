#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    int crr[1001]={0};
    vector<int> drr;

    for(int i=0;i<n;i++){
        cin>>x;
        if(crr[x]==0){
            drr.push_back(x);
        }
        crr[x]++;
    }

    sort(drr.begin(),drr.end());

    int cnt=0,ctr=0,sm=0;
    while(1){
        cnt=0;
        ctr=0;
        for(int i=0;i<drr.size();i++){
            x=drr[i];
            if(crr[x]>0){
                cnt=1;
                ctr++;
                crr[x]--;
            }

        }
        if(cnt==0)
            break;
        else{
            sm=sm+ctr-1;
        }
    }
    cout<<sm;
    return 0;
}
