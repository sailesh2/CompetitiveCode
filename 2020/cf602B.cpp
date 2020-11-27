#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int n,x;
    for(int i=0;i<t;i++){
        cin>>n;
        int q[n];
        int maxi=0;
          int ans=0;
            set<int> st;

            int ctr=1;

        for(int j=0;j<n;j++){
            cin>>x;
            maxi=max(maxi,x);
            if(st.count(x)==0){
                st.insert(x);
                q[j]=x;
            }else{
                int cnt=0;
                while(ctr<maxi){
                    if(st.count(ctr)==0){
                        st.insert(ctr);
                        q[j]=ctr;
                        cnt=1;
                        ctr++;
                        break;
                    }
                    ctr++;
                }
                if(cnt==0){
                    ans=-1;
                }
            }
        }
        if(ans==0){
            for(int j=0;j<n;j++)
                cout<<q[j]<<" ";
            cout<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
