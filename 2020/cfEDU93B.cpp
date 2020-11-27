#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        n = s.length();
        int sm=0;
        char prev;
        int ctr;
        vector<int> v;
        for(int j=0;j<n;j++){
            if(j==0){
                prev=s[j];
                ctr=1;
            }else{
                if(s[j]==prev)
                    ctr++;
                else{
                    if(prev=='1')
                        v.push_back(ctr);
                    ctr=1;
                    prev=s[j];
                }
            }
        }

        if(prev=='1')
            v.push_back(ctr);
        sort(v.begin(),v.end());
        for(int j=v.size()-1;j>=0;j=j-2){
            sm=sm+v[j];
        }
        cout<<sm<<"\n";
    }
    return 0;
}
