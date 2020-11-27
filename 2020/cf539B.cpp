#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,c;
    cin>>n;
    set<int> facSet;
    multiset<int> st;
    multiset<int>::iterator stIt;
    for(int i=0;i<n;i++){
        cin>>c;
        st.insert(c);
    }
    int sm=0;
    while(1){
        stIt=st.begin();
        int low=*stIt;

        stIt=st.end();
        stIt--;
        int high = *stIt;

        if(low==high){
           // cout<<low<<" --"<<st.size()<<"\n";
            sm=sm+low*st.size();
            break;
        }
        int lowSave=low;
        int highSave=high;
        int cnt=0,fac1,fac2,mini=low+high,facSave;
        for(int i=2;i*i<=high;i++){
            if(high%i==0){
                fac1=i;
                fac2=high/i;

                if(facSet.count(fac1)==0){
                    if(low*fac1+fac2<mini){
                        mini=low*fac1+fac2;
                        lowSave=low*fac1;
                        highSave=fac2;
                        facSave=fac1;
                        cnt=1;
                    }
                }
                if(facSet.count(fac2)==0){
                    if(fac1+low*fac2<mini){
                        mini=fac1+low*fac2;
                        lowSave=low*fac2;
                        highSave=fac1;
                        facSave=fac2;
                        cnt=1;
                    }
                }
            }
        }
        if(cnt==0){
            sm=sm+(*stIt);
            st.erase(stIt);
        }else{
            st.erase(stIt);
            st.erase(st.begin());

            st.insert(lowSave);
            st.insert(highSave);

            facSet.insert(facSave);
        }
    }
    cout<<sm;
    return 0;
}
