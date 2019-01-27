#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    int div[n];
    int maxi=0,maxi2=0;
    int has[100005]={0};
    int has2[100005]={0};
    vector<int> list1,list2;
    for(int i=0;i<n;i++){
        cin>>div[i];
        has[div[i]]++;
        maxi=max(maxi,div[i]);
    }
    for(int i=1;i<=maxi;i++){
        if(maxi%i==0 && has2[i]==0){
            if(has[i]==2)
                has2[i]=1;
            has[i]--;
        }
    }

    for(int i=0;i<n;i++){
        if(has[div[i]]>0)
            maxi2=max(maxi2,div[i]);
    }
    cout<<maxi<<" "<<maxi2;
    return 0;
}
