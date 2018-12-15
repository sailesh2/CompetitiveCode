#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;
int main(){
    int i,t,j,n,m;
    set<int>::iterator it,save;

    scanf("%d",&t);
    for(i=0;i<t;i++){
        set<int> st;
        scanf("%d%d",&n,&m);
        long long int p=1;
        char x;
        int y;
        int has[100005];
        for(j=0;j<m;j++){
            cin>>x>>y;
            st.insert(y);
            has[y]=int(x);
        }
        it=st.begin();
        save=it;
        it++;
        while(it!=st.end())
        {
            if(has[*it]!=has[*save])
            {
                p=((p*(*it-*save)%1000000009))%1000000009;
            }
            save=it;
            it++;
        }
        printf("%lld\n",p);
    }
    return 0;
}
