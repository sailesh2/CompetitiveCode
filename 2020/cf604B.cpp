#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int n,p;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        map<int,int> has;
        map<int,int>::iterator hasIt;
        int leftPos=-1,rightPos=-1;
        for(int j=0;j<n;j++){
            cin>>p;
            has.insert(make_pair(p,j));
        }
        string ans="";
        for(int j=1;j<=n;j++){
            hasIt=has.find(j);
            int pos = hasIt->second;
            if(leftPos==-1){
                leftPos=pos;
            }else{
                leftPos=min(leftPos,pos);
            }
            if(rightPos==-1){
                rightPos=pos;
            }else{
                rightPos=max(rightPos,pos);
            }
            int nums=rightPos-leftPos+1;
            if(nums==j){
                ans.push_back('1');
            }else{
                ans.push_back('0');
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
